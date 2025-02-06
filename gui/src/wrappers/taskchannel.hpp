#ifndef TASKCHANNEL_H_
#define TASKCHANNEL_H_

#include <QObject>
#include "taskwrapper.hpp"
#include "pluginAdapter.hpp"
#include "abstractedCommunicationadabter.hpp"

class TaskChannel :public QObject
{
    Q_OBJECT

public:
    explicit TaskChannel(QObject *parent = nullptr);
    TaskChannel& operator=(TaskChannel&& other) noexcept;


    Q_INVOKABLE QString send(TaskWrapper task);
    Q_INVOKABLE bool remove(QString id);
    Q_INVOKABLE bool update(TaskWrapper task);
    void setCommunicator(std::shared_ptr<AbstractedCommunicatorAdapter> com);

private:
    std::shared_ptr<AbstractedCommunicatorAdapter> mCommunicator;
};






#endif  // TASKCHANNEL_H_