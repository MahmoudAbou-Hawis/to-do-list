#include <QGuiApplication>
#include <QQmlApplicationEngine>
#include <QQmlContext>
#include <QQuickView>
#include "../GUI/src/wrappers/taskwrapper.hpp"
#include "../GUI/src/gui-initalizer/guiinitializer.hpp"
#include "../tasks/src/core-initializer/coreinitializer.hpp"

int main(int argc, char *argv[])
{

    QGuiApplication app(argc, argv);

    QQmlApplicationEngine engine;

    
    GuiInitializer g(&engine,std::make_shared<CoreInitializer>());


    const QUrl url(QStringLiteral("qrc:/GUI/src/qml/main.qml"));

    engine.load(url);

    return app.exec();
}
