#include "coreinitializer.hpp"
#include "dbFactory.hpp"

CoreInitializer::CoreInitializer()
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
