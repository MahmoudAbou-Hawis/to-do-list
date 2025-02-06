#include "taskwrapper.hpp"
#include "../utils/gui_helper.hpp"

TaskWrapper::TaskWrapper(const QString &name, bool checked, bool deleted, 
        int originalIndex, const QString &notes, 
        const QString &email, const QString &date, const QString &time,const QString &id)
    : mTask(std::make_shared<Task>(name.toStdString(), notes.toStdString(), 
                                    email.toStdString(), date.toStdString(), 
                                    time.toStdString(), originalIndex, deleted, checked,id.toStdString()))
{
}

TaskWrapper::TaskWrapper(const Task &t) 
    : TaskWrapper(make_qstring(t.name()), t.completed(), t.status(), 
                  t.originalIndex(), make_qstring(t.notes()), 
                  make_qstring(t.email()), make_qstring(t.date()), 
                  make_qstring(t.time()),make_qstring(t.id()))
{
}

QString TaskWrapper::getName() const
{
    return make_qstring(mTask->name());
}

bool TaskWrapper::getChecked() const
{
    return mTask->completed();
}

bool TaskWrapper::getDeleted() const
{
    return mTask->status();
}

int TaskWrapper::getOriginalIndex() const
{
    return mTask->originalIndex();
}

QString TaskWrapper::getNotes() const
{
    return make_qstring(mTask->notes());
}

QString TaskWrapper::getEmail() const
{
    return make_qstring(mTask->email());
}

QString TaskWrapper::getDate() const
{
    return make_qstring(mTask->date());
}

QString TaskWrapper::getTime() const
{
    return make_qstring(mTask->time());
}

QString TaskWrapper::getId() const
{
    return make_qstring(mTask->id());
}
