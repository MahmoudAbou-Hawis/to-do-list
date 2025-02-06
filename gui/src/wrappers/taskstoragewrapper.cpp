#include "taskstoragewrapper.hpp"
#include <QVariant>
#include <QList>
#include "gui_helper.hpp"

TaskStorageWrapper::TaskStorageWrapper(std::shared_ptr<TaskStorage> taskstorage,
                                       QObject *parent) : QObject(parent), mTaskStorage(taskstorage)
{
    std::vector<Task> recoveredTasks = mTaskStorage->getAllElements();
    
    for (const Task &t : recoveredTasks)
    {
        tasks.append(QVariant::fromValue(TaskWrapper(t)));
    }
}

TaskStorageWrapper &TaskStorageWrapper::operator=(TaskStorageWrapper &&other) noexcept
{
    if (this != &other)
    {
        mTaskStorage = std::move(other.mTaskStorage);
        tasks = std::move(other.tasks);
    }
    return *this;
}

TaskWrapper TaskStorageWrapper::makeTask(const QString &name, bool completed,
                                          bool status, int originalIndex,
                                          const QString &notes, const QString &email,
                                          const QString &date, const QString &time,
                                          const QString &id)
{
    return TaskWrapper(name, completed, status, originalIndex, notes, email, date, time,id);
}

bool TaskStorageWrapper::addTask(TaskWrapper task)
{
    return mTaskStorage->add(getTask(task));
}

bool TaskStorageWrapper::removeTask(TaskWrapper task)
{
    return mTaskStorage->remove(get_id(getTask(task)));
}

bool TaskStorageWrapper::updateTask(TaskWrapper task)
{
    return mTaskStorage->update(getTask(task));
}

QVariantList TaskStorageWrapper::getAllTasks()
{
    return tasks;
}

