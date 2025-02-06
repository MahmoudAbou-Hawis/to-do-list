#include "coreinitializer.hpp"
#include "dbFactory.hpp"
#include "abstractedCommunicationadabter.hpp"

CoreInitializer::CoreInitializer(std::shared_ptr<plugin_support::PluginCommunicatorWrapper> &&communicator) : mCommunicator(communicator)
{
}

CoreInitializer::~CoreInitializer()
{
}

void CoreInitializer::initDatabases()
{
    auto env = make_db_env(".");
    auto db = make_db("tasks",env);

    mTasksStorage = make_tasks_storage(db,env);

}

std::shared_ptr<TaskStorage> CoreInitializer::getTaskStorage() const
{
    return mTasksStorage;
}

std::shared_ptr<AbstractedCommunicatorAdapter> CoreInitializer::getPluginAdapter() const
{
    return std::make_shared<PluginAdapter>(mCommunicator);
}
