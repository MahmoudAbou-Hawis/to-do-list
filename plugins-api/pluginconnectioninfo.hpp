#ifndef PLUGINCONNECTIONINFO_H
#define PLUGINCONNECTIONINFO_H

#include <stdint.h>
#include "export-definition.hpp"

class EXPORTED PluginConnectionInfo {
 public:
  virtual ~PluginConnectionInfo() = default;

 public:
  [[nodiscard]] virtual const char* getPluginId() const noexcept = 0;
};

#endif  // PLUGINCONNECTIONINFO_H
