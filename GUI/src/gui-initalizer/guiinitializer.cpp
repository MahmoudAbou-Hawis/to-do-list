#include "guiinitializer.hpp"
#include "AbstractCoreInitializer.hpp"
#include "taskwrapper.hpp"
#include "taskstoragewrapper.hpp"
#include <QQmlApplicationEngine>
#include <QQmlContext>

GuiInitializer::GuiInitializer(QQmlApplicationEngine *appEngine, 
                               const std::shared_ptr<AbstractCoreInitializer> &coreInit)
                            
{
    coreInit->initDatabases();
    std::shared_ptr<TaskStorage> store = coreInit->getTaskStorage();

    qRegisterMetaType<TaskWrapper>(); 
    
    TaskStorageWrapper w(store);
    s = std::move(w);
    appEngine->rootContext()->setContextProperty("store", &s);

}
