#include "plugininterface.hpp"
#include "pluginhcommunicatorwrapper.hpp"
#include "supportfunctions.hpp"
#include <memory>
#include <iostream>

plugin_support::PluginInterface::PluginInterface(PluginFacade *facade) : mFacade(facade)
{
}

std::string plugin_support::PluginInterface::getId() const noexcept
{
    return make_string(mFacade->getId());
}

std::shared_ptr<plugin_support::PluginCommunicatorWrapper>
plugin_support::PluginInterface::makeCommunicator() noexcept
{
    return std::make_shared<plugin_support::PluginCommunicatorWrapper>(
        std::unique_ptr<PluginCommunicator, own_deleter>(mFacade->makeCommunicator(), mFacade),mFacade);
}

std::shared_ptr<const PluginAddressValidator>
plugin_support::PluginInterface::getAddressValidator()
{
    return std::shared_ptr<const PluginAddressValidator>(mFacade->getAddressValidator(),
                                                         [_interface = this->shared_from_this()](const auto *) {

                                                         });
}
