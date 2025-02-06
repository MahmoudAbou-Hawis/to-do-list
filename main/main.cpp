#include <QGuiApplication>
#include <QQmlApplicationEngine>
#include <QQmlContext>
#include <QQuickView>
#include "../gui/src/wrappers/taskwrapper.hpp"
#include "../gui/src/gui-initalizer/guiinitializer.hpp"
#include "../tasks/src/core-initializer/coreinitializer.hpp"
#include "plugin-support/src/pluginloader.hpp"
#include <spdlog/sinks/rotating_file_sink.h>
#include <spdlog/spdlog.h>
#include "../tasks/src/adapters/pluginAdapter.hpp"
#include "../tasks/src/primitives/task.hpp"
#include <string>
#include <chrono>
#include <thread>
#include <iostream>
#include "../gui/src/gui-initalizer/loginintalizer.hpp"
#include <QTimer>
int main(int argc, char *argv[])
{

    QGuiApplication app(argc, argv);

    QQmlApplicationEngine engine;
    spdlog::rotating_logger_mt("root_logger", "to-do.log", 1048576 * 5,
                             3);

    
    LoginInitializer l(&engine);
    const QUrl url(QStringLiteral("qrc:/gui/src/qml/login.qml"));

    engine.load(url);

    return app.exec();
}
