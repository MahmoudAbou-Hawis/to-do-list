#ifndef DBFACTORY_H
#define DBFACTORY_H

#include <stdint.h>
#include <string>
#include <memory>
class DbEnv;
class Db;

std::shared_ptr<DbEnv> make_db_env(const std::string& path);
std::shared_ptr<Db> make_db(const std::string& file,
            std::weak_ptr<DbEnv> penv);

#endif  // DBFACTORY_H