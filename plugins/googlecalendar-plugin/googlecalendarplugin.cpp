#include "googlecalendarplugin.hpp"
#include "inner/plugindef.hpp"

#include "googlecalendarfacade.hpp"

static GoogleCalendarFacade facade;

extern "C" PluginFacade* get_to_do_plugin_facade() {
  return &facade;
}

const char* getPluginId() {
  return "3ccacfb5-b8be-42da-a9c8-3098e68dd76d";
}
