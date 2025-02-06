#include "loginintalizer.hpp"
#include <QQmlContext>

LoginInitializer::LoginInitializer(QQmlApplicationEngine *engine)
{
    mLoader.setEngine(engine);

    engine->rootContext()->setContextProperty("login", &mLoader);
}
