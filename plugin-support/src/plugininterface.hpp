#ifndef PLIGININTERFACE_H_
#define PLIGININTERFACE_H_

#include "export/pluginfacade.hpp"
#include "pluginhcommunicatorwrapper.hpp"
#include <string>

namespace plugin_support
{


    class PluginInterface : public std::enable_shared_from_this<PluginInterface>
    {
    public:
        PluginInterface(PluginFacade *facade);

    public:
        std::string getId() const noexcept;

    public:
        std::shared_ptr<PluginCommunicatorWrapper> makeCommunicator() noexcept;
        std::shared_ptr<const PluginAddressValidator> getAddressValidator();

    private:
        PluginFacade *mFacade;
    };
}

#endif