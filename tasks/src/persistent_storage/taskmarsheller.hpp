#ifndef TASKMARSHELLER_HPP
#define TASKMARSHELLER_HPP

#include <cstdint>

class Task;

class TaskMarshaller
{
public:
    static void restore(Task &elem, const void *src);
    static void store(void *dest, const Task &elem);
    static uint32_t size(const Task &element);
};

#endif // TASKMARSHELLER_HPP