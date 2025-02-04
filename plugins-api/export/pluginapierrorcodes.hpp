#ifndef PLUGINAPIERRORCODES_H
#define PLUGINAPIERRORCODES_H

#include "export-definition.hpp"

enum class PluginApiErrorCodes {
  NoError,
  NotAuthorized,
  SendFailed,
  InvalidTime,
  UpdateFailed,
  DeleteFailed,
  DateErrorFormat,
  Disconected
};

#endif  // PLUGINAPIERRORCODES_H
