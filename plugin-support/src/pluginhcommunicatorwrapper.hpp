#ifndef PLUGINCOMMUNICATORWRAPPER_H_
#define PLUGINCOMMUNICATORWRAPPER_H_

#include "export/plugincommuincator.hpp"
#include "own_deleter.hpp"
#include <vector>

namespace plugin_support
{
    class PluginCommunicatorWrapper
    {
        public:
            PluginCommunicatorWrapper(std::unique_ptr<PluginCommunicator , own_deleter> &&communicator,PluginFacade * facade);
            
    [[nodiscard]]  PluginApiErrorCodes add(
        std::string &TaskName,
        std::string &description,
        std::string &starttime,
        std::string &endtime,
        std::vector<std::string> &attendance,
        std::string & id);
    [[nodiscard]]  PluginApiErrorCodes remove(std::string id) noexcept ;
    [[nodiscard]]  PluginApiErrorCodes update(std::string id,        
        std::string TaskName,
        std::string description,
        std::string starttime,
        std::string endtime,
        std::vector<std::string> &attendance) noexcept;
    [[nodiscard]]  PluginApiErrorCodes connect() noexcept;


        private:
            std::unique_ptr<PluginCommunicator , own_deleter> mCommunicator;
            PluginFacade * mFacade;
    };
}


#endif