#ifndef TASKWRAPPER_HPP
#define TASKWRAPPER_HPP

#include <QString>
#include <QMetaObject>
#include <QMetaType>
#include <memory>
#include "../../../tasks/src/primitives/task.hpp"

class TaskWrapper {
    Q_GADGET

    // Define the properties
    Q_PROPERTY(QString name READ getName CONSTANT)
    Q_PROPERTY(bool checked READ getChecked CONSTANT)
    Q_PROPERTY(bool deleted READ getDeleted CONSTANT)
    Q_PROPERTY(int originalIndex READ getOriginalIndex CONSTANT)
    Q_PROPERTY(QString notes READ getNotes CONSTANT)
    Q_PROPERTY(QString email READ getEmail CONSTANT)
    Q_PROPERTY(QString date READ getDate CONSTANT)
    Q_PROPERTY(QString time READ getTime CONSTANT)

public:
    TaskWrapper(const QString &name, bool checked, bool deleted, 
                int originalIndex, const QString &notes, 
                const QString &email, const QString &date, const QString &time);
    TaskWrapper(const Task &t) ;
    TaskWrapper(){};
    ~TaskWrapper(){};

    // Getter methods for properties
    QString getName() const;
    bool getChecked() const;
    bool getDeleted() const;
    int getOriginalIndex() const;
    QString getNotes() const;
    QString getEmail() const;
    QString getDate() const;
    QString getTime() const;

private:
    std::shared_ptr<Task> mTask;  // Assuming Task is a class you have defined elsewhere
};

Q_DECLARE_METATYPE(TaskWrapper)

#endif
