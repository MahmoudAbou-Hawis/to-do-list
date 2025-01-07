#include "storage.hpp"
#include <gtest/gtest.h>
#include <string>
#include <vector>
#include "dbFactory.hpp"

class TestElement
{
public:
    std::string id;
    std::string name;
};

std::string get_id(const TestElement &Element)
{
    return Element.id;
}

bool operator==(const TestElement& lhs, const TestElement& rhs) {
    return lhs.id == rhs.id && lhs.name == rhs.name;
}

void * save_str(const std::string &element,void * dest)
{
    auto size = element.length();
    memcpy(dest,&size,sizeof(size));
    char * destBuffer = static_cast<char*>(dest) + sizeof(size);
    memcpy(destBuffer,element.c_str(),element.size());
    return static_cast<char*>(destBuffer) + element.size();
}

const void* restore_str(std::string& str, const void* src)
{
    std::string::size_type size;
    memcpy(&size,src,sizeof(size));
    const char * Strsrc = static_cast<const char*>(src) + sizeof(size);   
    str.reserve(size);
    str.insert(0,static_cast<const char *>(Strsrc),size);
    return static_cast<const char *>(Strsrc) + size;
}

class TestMarshaller
{
public:
    static void restore(TestElement &elem, const void *src)
    {
        src = restore_str(elem.id,src);
        src = restore_str(elem.name,src); 
    }
    static void store(void* dest, const TestElement& elem)
    {
        dest = save_str(elem.id,dest);
        dest = save_str(elem.name,dest);

    }
    static u_int32_t size(const TestElement& element)
    {
        return 2 * sizeof(std::string::size_type) + element.id.length() + element.name.length();
    }
    
};


TEST(StorageTest, addElementandRestoreTheElement)
{

    auto env = make_db_env(".");
    auto db = make_db("test_db",env);
    prstorage::Storage<TestElement, TestMarshaller> store(db,env);


    

    TestElement elem1{"1", "ahmed"},
    elem2{"2", "Mahmoud"};
    ASSERT_TRUE(store.add(elem1));
    ASSERT_TRUE(store.add(elem2));

    auto retrive = store.get(get_id(elem1));
    auto retrive2 = store.get(get_id(elem2));

    ASSERT_EQ(retrive.id,elem1.id);
    ASSERT_EQ(retrive.name,elem1.name);

    ASSERT_EQ(retrive2.id,elem2.id);
    ASSERT_EQ(retrive2.name,elem2.name);
    
}

TEST(StorageTest, addSameElements)
{
    auto env = make_db_env(".");
    auto db = make_db("test_db",env);
    prstorage::Storage<TestElement, TestMarshaller> store(db,env);

    TestElement elem1{"1", "ahmed"},
    elem2{"2", "Mahmoud"};
    ASSERT_FALSE(store.add(elem1));
    ASSERT_FALSE(store.add(elem2));

    auto retrive = store.get(get_id(elem1));
    auto retrive2 = store.get(get_id(elem2));

    ASSERT_EQ(retrive.id,elem1.id);
    ASSERT_EQ(retrive.name,elem1.name);

    ASSERT_EQ(retrive2.id,elem2.id);
    ASSERT_EQ(retrive2.name,elem2.name);
    
}


TEST(StorageTest, updateExistElements)
{
    auto env = make_db_env(".");
    auto db = make_db("test_db",env);
    prstorage::Storage<TestElement, TestMarshaller> store(db,env);

    TestElement elem1{"1", "Mahmoud"},
    elem2{"2", "ahmed"};
    ASSERT_TRUE(store.update(elem1));
    ASSERT_TRUE(store.update(elem2));

    auto retrive = store.get(get_id(elem1));
    auto retrive2 = store.get(get_id(elem2));

    ASSERT_EQ(retrive.id,elem1.id);
    ASSERT_EQ(retrive.name,elem1.name);

    ASSERT_EQ(retrive2.id,elem2.id);
    ASSERT_EQ(retrive2.name,elem2.name);
    
}


TEST(StorageTest, removeExistElement)
{
    auto env = make_db_env(".");
    auto db = make_db("test_db",env);
    prstorage::Storage<TestElement, TestMarshaller> store(db,env);

    ASSERT_TRUE(store.remove("1"));

}


TEST(StorageTest, removeNonExistElement)
{
    auto env = make_db_env(".");
    auto db = make_db("test_db",env);
    prstorage::Storage<TestElement, TestMarshaller> store(db,env);

    ASSERT_FALSE(store.remove("4"));

}

TEST(StorageTest, ReturnAllData)
{
    auto env = make_db_env(".");
    auto db = make_db("test_db",env);
    prstorage::Storage<TestElement, TestMarshaller> store(db,env);

   std::vector<TestElement> result = store.getAllElements();

   std::vector<TestElement> expected = { TestElement{"1", "Mahmoud"},
    TestElement{"2", "ahmed"}};

    ASSERT_FALSE(expected == result);
}


TEST(StorageTest, updateNonExistElement)
{
    auto env = make_db_env(".");
    auto db = make_db("test_db",env);
    auto store  = std::make_shared<prstorage::Storage<TestElement, TestMarshaller>>(db,env);
    
    auto s2 = store->getSharedObject();

    TestElement element {"5","sofar"};



    ASSERT_FALSE(store->update(element));
}
