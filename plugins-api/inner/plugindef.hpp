#ifndef PLUGININNERDEFS_H
#define PLUGININNERDEFS_H

#include "plugins-api/export-definition.hpp"

class PluginFacade;

extern "C" EXPORTED PluginFacade* get_secure_dialogues_plugin_facade();

#endif  // PLUGININNERDEFS_H
