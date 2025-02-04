#include "pluginhcommunicatorwrapper.hpp"
#include "export/pluginaddressvalidator.hpp"
#include "supportfunctions.hpp"
plugin_support::PluginCommunicatorWrapper::
    PluginCommunicatorWrapper(std::unique_ptr<PluginCommunicator, own_deleter>
                                  &&communicator,
                              PluginFacade *facade) : mCommunicator(std::move(communicator)), mFacade(facade)
{
}

PluginApiErrorCodes plugin_support::PluginCommunicatorWrapper::add(
                            std::string &TaskName, std::string &description, 
                            std::string &starttime, std::string &endtime,
                             std::vector<std::string> &attendance,std::string &id)
{
    auto Validator = mFacade->getAddressValidator();
    auto verifyStartData = Validator->isValid(starttime.c_str());
    auto verifyEndData = Validator->isValid(endtime.c_str());
    if (verifyEndData == PluginApiErrorCodes::NoError && verifyStartData == PluginApiErrorCodes::NoError)
    {
        std::vector<const char *> attendancePtrs;
        attendancePtrs.reserve(attendance.size());  
        for (const auto &attendee : attendance)
        {
            attendancePtrs.push_back(attendee.c_str());
        }
        char *result = nullptr;
        auto ret = mCommunicator->add(TaskName.c_str(), description.c_str(), starttime.c_str(), endtime.c_str(), attendancePtrs.data(), attendance.size(), &result);
        if(ret == PluginApiErrorCodes::NoError )
        {
            id = make_string(result);
            delete[] result;
        }
        return ret;
    }
    return PluginApiErrorCodes::NoError;
}

PluginApiErrorCodes plugin_support::PluginCommunicatorWrapper::remove(std::string id) noexcept
{
    return mCommunicator->remove(id.c_str());
}

PluginApiErrorCodes plugin_support::PluginCommunicatorWrapper::update(std::string id, std::string TaskName, std::string description, std::string starttime, std::string endtime, std::vector<std::string> &attendance) noexcept
{
    auto Validator = mFacade->getAddressValidator();
    auto verifyStartData = Validator->isValid(starttime.c_str());
    auto verifyEndData = Validator->isValid(endtime.c_str());
    if (verifyEndData == PluginApiErrorCodes::NoError && verifyStartData == PluginApiErrorCodes::NoError)
    {
        std::vector<const char *> attendancePtrs;
        attendancePtrs.reserve(attendance.size());  
        for (const auto &attendee : attendance)
        {
            attendancePtrs.push_back(attendee.c_str());
        }
        char *result = nullptr;
        return mCommunicator->update(id.c_str(),TaskName.c_str(), description.c_str(), starttime.c_str(), endtime.c_str(), attendancePtrs.data(), attendance.size());

    }
    return PluginApiErrorCodes::NoError;
}

PluginApiErrorCodes plugin_support::PluginCommunicatorWrapper::connect() noexcept
{
    return mCommunicator->connect();
}