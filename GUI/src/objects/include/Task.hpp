#ifndef TASK_HPP
#define TASK_HPP

#include <QString>
#include <QMetaObject>
#include <QMetaType>

class Task {
    Q_GADGET
    Q_PROPERTY(QString MEMBER m_name)
    Q_PROPERTY(bool MEMBER m_checked)
    Q_PROPERTY(bool MEMBER m_deleted)  
    Q_PROPERTY(double MEMBER m_textOpacity)
    Q_PROPERTY(int MEMBER m_originalIndex)
    Q_PROPERTY(QString MEMBER m_notes)
    Q_PROPERTY(QString MEMBER m_email)
    Q_PROPERTY(QString MEMBER m_date)
    Q_PROPERTY(QString MEMBER m_time)
    
public:
    Task(const QString &name, bool checked, bool deleted, 
         double textOpacity, int originalIndex, const QString &notes, 
         const QString &email, const QString &date, const QString &time);
    ~Task();

    Q_INVOKABLE QString toString() const;
    QString getName() const;
    bool getChecked() const;
    bool getDeleted() const;
    double getTextOpacity() const;
    int getOriginalIndex() const;
    QString getNotes() const;
    QString getEmail() const;
    QString getDate() const;
    QString getTime() const;

private:
    QString m_name;
    bool m_checked;
    bool m_deleted;
    double m_textOpacity;
    int m_originalIndex;
    QString m_notes;
    QString m_email;
    QString m_date;
    QString m_time;
};

#endif // TASK_HPP