#include <gtest/gtest.h>
#include "task.hpp"
#include "taskmarsheller.hpp"
#include <string>


TEST(TaskMarshellerTest, CheckIfTheTaskMarshellerAsExpected)
{
    Task t(static_cast<const char*>("name"),static_cast<const char*>("date"),static_cast<const char*>("email"),static_cast<const char*>("date"),static_cast<const char*>("time"),5,true,true);
    char * buff = new char[TaskMarshaller::size(t)];
    TaskMarshaller::store(buff,t);
    Task returnedTask;
    TaskMarshaller::restore(returnedTask,buff);


    ASSERT_EQ(returnedTask.name(),t.name());
    ASSERT_EQ(returnedTask.date(),t.date());
    ASSERT_EQ(returnedTask.notes(),t.notes());
    ASSERT_EQ(returnedTask.email(),t.email());
    ASSERT_EQ(returnedTask.time(),t.time());
    ASSERT_EQ(returnedTask.status(),t.status());
    ASSERT_EQ(returnedTask.originalIndex(),t.originalIndex());
    ASSERT_EQ(returnedTask.completed(),t.completed());

    delete [] buff;
}