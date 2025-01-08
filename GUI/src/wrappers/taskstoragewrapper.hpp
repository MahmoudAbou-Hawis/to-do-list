#ifndef TASKSTORAGEWRAPPER_H_
#define TASKSTORAGEWRAPPER_H_

#include <QObject>
#include <QVariantList>
#include "storages.hpp"
#include "taskwrapper.hpp"

class TaskStorageWrapper : public QObject
{
    Q_OBJECT

public:
    explicit TaskStorageWrapper(std::shared_ptr<TaskStorage> taskstorage,
                                QObject* parent = nullptr);
    TaskStorageWrapper() {};

    TaskStorageWrapper& operator=(TaskStorageWrapper&& other) noexcept;

    Q_INVOKABLE TaskWrapper makeTask(const QString &name, bool completed, bool status,
                                     int originalIndex, const QString &notes, 
                                     const QString &email, const QString &date,
                                     const QString &time);
    Q_INVOKABLE bool addTask(TaskWrapper task);
    Q_INVOKABLE bool removeTask(TaskWrapper task);
    Q_INVOKABLE bool updateTask(TaskWrapper task);
    Q_INVOKABLE QVariantList getAllTasks();

private:
    std::shared_ptr<TaskStorage> mTaskStorage;
    QVariantList tasks;
    
    // Helper method to convert TaskWrapper to Task
    Task getTask(TaskWrapper task);
    
};

#endif