#include "taskchannel.hpp"
#include "../utils/gui_helper.hpp"
#include <QString>

TaskChannel::TaskChannel(QObject *parent) : QObject(parent)
{
}

TaskChannel &TaskChannel::operator=(TaskChannel &&other) noexcept
{
    if (this != &other)
    {
        mCommunicator = std::move(other.mCommunicator);
    }
    return *this;
}

Q_INVOKABLE QString TaskChannel::send(TaskWrapper task)
{
    Task h = getTask(task);
    return make_qstring(mCommunicator->send(h));
}

Q_INVOKABLE bool TaskChannel::remove(QString id)
{
    return mCommunicator->remove(id.toStdString());
}

Q_INVOKABLE bool TaskChannel::update(TaskWrapper task)
{
    Task h = getTask(task);
    return mCommunicator->update(h);
}

void TaskChannel::setCommunicator(std::shared_ptr<AbstractedCommunicatorAdapter> com)
{
    mCommunicator = std::move(com);
}
