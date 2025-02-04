#ifndef PLUGINADDRESSVALIDATOR_H
#define PLUGINADDRESSVALIDATOR_H

#include "export-definition.hpp"
#include "pluginapierrorcodes.hpp"

class EXPORTED PluginAddressValidator {
 public:
  virtual ~PluginAddressValidator() = default;

 public:
  [[nodiscard]] virtual PluginApiErrorCodes isValid(const char* address) const
      noexcept = 0;
};

#endif  // PLUGINADDRESSVALIDATOR_H
