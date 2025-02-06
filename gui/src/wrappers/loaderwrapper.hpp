#ifndef LOADERWRAPPER_H_
#define LOADERWRAPPER_H_

#include <QString>
#include "plugin-support/src/pluginloader.hpp"
#include "../gui-initalizer/guiinitializer.hpp"
#include <memory>

class QQmlApplicationEngine;

class LoaderWrapper : public QObject
{
    Q_OBJECT
    public:
        LoaderWrapper();
        ~LoaderWrapper(){};
        Q_INVOKABLE bool loadGoogle();
        Q_INVOKABLE bool connect();
        Q_INVOKABLE void gotoApp();
        void setEngine(QQmlApplicationEngine *engine);
    private:
        std::shared_ptr<plugin_support::PluginInterface> mPlugin;
        std::shared_ptr<plugin_support::PluginCommunicatorWrapper> mCommunicator;
        QQmlApplicationEngine * mEngine;
        std::shared_ptr<GuiInitializer> mGuiInit;
};

#endif