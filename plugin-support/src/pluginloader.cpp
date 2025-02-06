#include "pluginloader.hpp"
#include <dlfcn.h>
#include <dynalo/dynalo.hpp>
#include <nlohmann/json.hpp>
#include <boost/filesystem.hpp>
#include <spdlog/spdlog.h>
#include <optional>
#include <stdexcept>
#include "inner/plugindef.hpp"
#include <iostream>


std::optional<nlohmann::json> isValid(const std::string& path)
{
    try
    {
        std::ifstream in{path};
        if(!in)
            return {};
        nlohmann::json descr = nlohmann::json::parse(in);
        return descr;
    }
    catch(const std::exception &e)
    {
        auto logger = spdlog::get("root_logger");
        logger->warn("Failed to validate the schema with error {}",e.what());
    }
    return {};
}




std::shared_ptr<plugin_support::PluginInterface> 
plugin_support::plugin_loader(std::string schema_path, 
                              std::string plugin_path)
{
  using nlohmann::json;
  
  auto desc = isValid(schema_path);

   if(desc.has_value())
   {
        auto json = desc.value();
        plugin_path.append("/").append(json["root-module"]);
        try
        {
            dynalo::library lib(plugin_path);
            auto func = lib.get_function<decltype(get_to_do_plugin_facade)>("get_to_do_plugin_facade");
            return std::make_shared<plugin_support::PluginInterface>(func());
        }   
        catch(std::exception& ex)
        {
           spdlog::get("root_logger")->warn("Failed to load plugin in path {} with error {}",
                       plugin_path,
                       ex.what());
        }
   }
   return std::shared_ptr<plugin_support::PluginInterface>();;
}
