#include "storages.hpp"
#include "dbFactory.hpp"
#include <gtest/gtest.h>



TEST(TaskSavingTest, EnsureTheTaskSavedAndRetrived)
{
    auto env = make_db_env(".");
    auto db = make_db("test_db",env);

    auto storage = make_tasks_storage(db,env);

    Task t(static_cast<const char*>("name"),static_cast<const char*>("date"),static_cast<const char*>("email"),static_cast<const char*>("date"),static_cast<const char*>("time"),0,true,true);

    ASSERT_TRUE(storage->add(t));


   auto tastRetrived =  storage->get(get_id(t));

    ASSERT_EQ(tastRetrived.name(),t.name());
    ASSERT_EQ(tastRetrived.date(),t.date());
    ASSERT_EQ(tastRetrived.notes(),t.notes());
    ASSERT_EQ(tastRetrived.email(),t.email());
    ASSERT_EQ(tastRetrived.time(),t.time());
    ASSERT_EQ(tastRetrived.status(),t.status());
    ASSERT_EQ(tastRetrived.originalIndex(),t.originalIndex());
    ASSERT_EQ(tastRetrived.completed(),t.completed());
   
}