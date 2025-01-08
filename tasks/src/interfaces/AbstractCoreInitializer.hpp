#ifndef ABSTRACTCOREINITIALIZER_H
#define ABSTRACTCOREINITIALIZER_H

#include <memory>

#include "storages.hpp"


class AbstractCoreInitializer {
 public:
  virtual ~AbstractCoreInitializer() = default;

 public:
    virtual void initDatabases() = 0;
    virtual std::shared_ptr<TaskStorage> getTaskStorage() const = 0;

};

#endif  // ABSTRACTCOREINITIALIZER_H