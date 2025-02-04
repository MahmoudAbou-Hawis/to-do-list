#ifndef PLUGINLOADER_H_
#define PLUGINLOADER_H_

#include "plugininterface.hpp"
#include <memory>

namespace plugin_support {


std::shared_ptr<PluginInterface> plugin_loader(std::string schema, std::string plugin);

}

#endif