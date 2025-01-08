#ifndef STORAGES_H_
#define STORAGES_H_

#include "task.hpp"
#include "storage.hpp"
#include "taskmarsheller.hpp"

std::string get_id(const Task& task);


using TaskStorage = prstorage::Storage<Task,TaskMarshaller>;



std::shared_ptr<TaskStorage> make_tasks_storage(
    std::shared_ptr<Db> &pdb,
    std::shared_ptr<DbEnv> &penv);


#endif