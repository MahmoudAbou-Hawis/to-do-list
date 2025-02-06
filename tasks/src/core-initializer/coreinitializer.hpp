#ifndef COREINITIALIZER_H_
#define COREINITIALIZER_H_

#include "AbstractCoreInitializer.hpp"
#include "plugin-support/src/pluginhcommunicatorwrapper.hpp"
#include "pluginAdapter.hpp"

class CoreInitializer: public AbstractCoreInitializer
{
    public:
        CoreInitializer(std::shared_ptr<plugin_support::PluginCommunicatorWrapper> &&communicator);
        ~CoreInitializer() ;
    public:
        void initDatabases()  override;
        std::shared_ptr<TaskStorage> getTaskStorage() const override ;
        std::shared_ptr<AbstractedCommunicatorAdapter> getPluginAdapter() const override;

    private:
        std::shared_ptr<TaskStorage> mTasksStorage;
        std::shared_ptr<plugin_support::PluginCommunicatorWrapper> mCommunicator;
};



#endif