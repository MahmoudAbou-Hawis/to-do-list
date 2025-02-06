#include "taskmarsheller.hpp"
#include "task.hpp"
#include "store_helpers.hpp"

void TaskMarshaller::restore(Task &elem, const void *src)
{
    std::string date,email,notes,time,name,id;
    bool completed,status;
    int original;
    src = restore_simple_type(completed,src);
    src = restore_simple_type(original,src);
    src = restore_simple_type(status,src);
    src = restore_str(date,src);
    src = restore_str(email,src);
    src = restore_str(name,src);
    src = restore_str(notes,src);
    src = restore_str(time,src);
    src = restore_str(id,src);
    elem =  Task(name, notes, email, date, time, original, 
                status,  completed,id);
}

void TaskMarshaller::store(void *dest, const Task &elem)
{
    dest = save_simple_type(elem.completed(),dest);
    dest = save_simple_type(elem.originalIndex(),dest);
    dest = save_simple_type(elem.status(),dest);
    dest = save_str(elem.date(),dest);
    dest = save_str(elem.email(),dest);
    dest = save_str(elem.name(),dest);
    dest = save_str(elem.notes(),dest);
    dest = save_str(elem.time(),dest);
    dest = save_str(elem.id(),dest);
}

uint32_t TaskMarshaller::size(const Task &element)
{
    uint32_t size = 0;
    size += sizeof(std::string::size_type) + element.date().length();
    size += sizeof(std::string::size_type) + element.time().length();
    size += sizeof(std::string::size_type) + element.notes().length();
    size += sizeof(std::string::size_type) + element.email().length();
    size += sizeof(std::string::size_type) + element.name().length();
    size += sizeof(element.completed());
    size += sizeof(element.originalIndex());
    size += sizeof(element.status());
    size += sizeof(std::string::size_type) + element.id().length();
    return size;
}
