#ifndef PLUGINAPIERRORCODES_H
#define PLUGINAPIERRORCODES_H

#include "export-definition.hpp"

enum class PluginApiErrorCodes {
  NoError,
  Disconected,
  NotAuthorized,
  SendFailed,
  RecieveFailed,
  InvalidAddress
};

#endif  // PLUGINAPIERRORCODES_H
