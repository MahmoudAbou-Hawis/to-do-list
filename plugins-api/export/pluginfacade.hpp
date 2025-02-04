#ifndef PLAGINFACADE_H
#define PLAGINFACADE_H


#include "export-definition.hpp"

class PluginConnectionInfo;
class PluginCommunicator;
class PluginAddressValidator;

class EXPORTED PluginFacade {
 public:
  virtual ~PluginFacade() = default;

 public:
  [[nodiscard]] virtual const char* getId() const noexcept = 0;

 public:

  [[nodiscard]] virtual PluginCommunicator* makeCommunicator() noexcept = 0;
  [[nodiscard]] virtual const PluginAddressValidator* getAddressValidator()
      const noexcept = 0;

 public:
  virtual void release(PluginCommunicator* comm) noexcept = 0;
};

#endif  // PLAGINFACADE_H
