#ifndef GUI_HELPERS_H
#define GUI_HELPERS_H

#include <QString>
#include <string_view>
#include "task.hpp"
#include "taskwrapper.hpp"

inline QString make_qstring(std::string_view view) {
  return QString::fromUtf8(view.data(), static_cast<int>(view.size()));
}

inline Task getTask(TaskWrapper task)
{
    return Task(task.getName().toStdString(), task.getNotes().toStdString(),
                task.getEmail().toStdString(), task.getDate().toStdString(),
                task.getTime().toStdString(), task.getOriginalIndex(), task.getDeleted(),
                task.getChecked(),task.getId().toStdString());
}

#endif  
