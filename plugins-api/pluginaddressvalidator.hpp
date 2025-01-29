#ifndef PLUGINADDRESSVALIDATOR_H
#define PLUGINADDRESSVALIDATOR_H

#include "export-definition.hpp"

class EXPORTED PluginAddressValidator {
 public:
  virtual ~PluginAddressValidator() = default;

 public:
  [[nodiscard]] virtual const char* isValid(const char* address) const
      noexcept = 0;
  [[nodiscard]] virtual const char* peelAddress(const char* address) const
      noexcept = 0;  
};

#endif  // PLUGINADDRESSVALIDATOR_H
