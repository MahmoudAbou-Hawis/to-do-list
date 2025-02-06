#include "loaderwrapper.hpp"
#include <QQmlApplicationEngine>
#include <QObject>
#include "tasks/src/core-initializer/coreinitializer.hpp"

LoaderWrapper::LoaderWrapper() 
{
}

bool LoaderWrapper::loadGoogle()
{
    mPlugin = plugin_support::plugin_loader("/home/mahmoud/todo_project/to-do-list/build/plugins/googlecalendar-plugin/GoogleCalender.plugin/description.json",
    "/home/mahmoud/todo_project/to-do-list/build/plugins/googlecalendar-plugin");

    return mPlugin != nullptr;
}

bool LoaderWrapper::connect()
{
    if(mPlugin)
    {
        mCommunicator = mPlugin->makeCommunicator();
        return mCommunicator->connect() == PluginApiErrorCodes::NoError;
        
    }
    return false;
}

void LoaderWrapper::gotoApp()
{
        mGuiInit = std::make_shared<GuiInitializer>(mEngine, std::make_shared<CoreInitializer>(std::move(mCommunicator)));
        const QUrl url(QStringLiteral("qrc:/gui/src/qml/main.qml"));
        mEngine->clearComponentCache();
        if (mEngine->rootObjects().size() > 0) {
            QObject* rootObject = mEngine->rootObjects().at(0);
            rootObject->deleteLater(); 
        }
        mEngine->load(url);
}

void LoaderWrapper::setEngine(QQmlApplicationEngine *engine)
{
    mEngine =  engine;
}
