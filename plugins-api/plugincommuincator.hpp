#ifndef PLUGINMESSAGECOMMUNICATOR_H
#define PLUGINMESSAGECOMMUNICATOR_H

#include "export-definition.hpp"
#include "pluginapierrorcodes.hpp"

class PluginConnectionInfo;

class EXPORTED PluginCommunicator {
 public:
  virtual ~PluginCommunicator() = default;

 public:
  [[nodiscard]] virtual PluginApiErrorCodes add(
      const char* TaskName,
      const char * description,
      const char * starttime,
      const char * endtime,
      const char * attendances,
      const char* message) noexcept = 0;
  [[nodiscard]] virtual PluginApiErrorCodes connect(
      const PluginConnectionInfo* connInfo) noexcept = 0;
};

#endif  // PLUGINMESSAGECOMMUNICATOR_H
