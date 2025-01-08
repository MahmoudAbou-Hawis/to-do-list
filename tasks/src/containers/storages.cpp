#include "storages.hpp"

std::string get_id(const Task &task)
{
    int size = 0;
    for(auto &i : task.name())
    {
        size += static_cast<int>(i);
    }
    return std::string(std::to_string(size));
}

std::shared_ptr<TaskStorage> make_tasks_storage(
    std::shared_ptr<Db> &db, std::shared_ptr<DbEnv> &env)
{
    return std::make_shared<TaskStorage>(db, env);
}