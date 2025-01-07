#include "dbFactory.hpp"
#include <db_cxx.h>
#include <iostream>

std::shared_ptr<DbEnv> make_db_env(const std::string& path)
{
    std::shared_ptr<DbEnv> env(new DbEnv(DB_CXX_NO_EXCEPTIONS), [](DbEnv* ptr) {
    ptr->close(0);
    });
    env->open(path.c_str(), DB_CREATE | DB_INIT_MPOOL, 0);
    return env;
}

std::shared_ptr<Db> make_db(const std::string& file,
            std::weak_ptr<DbEnv> penv)
{
    std::shared_ptr<DbEnv> env = penv.lock();
    if(!env)
    {
        throw std::runtime_error("Environment is expired.");
    }
    std::shared_ptr<Db> db(new Db(env.get(), DB_CXX_NO_EXCEPTIONS), [](Db* db) {
        db->close(0);
    });
    db->open(nullptr,file.c_str(),nullptr,DB_BTREE,DB_CREATE,0);
    return db;
}