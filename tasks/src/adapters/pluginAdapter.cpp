#include "pluginAdapter.hpp"
#include <string>


std::string make_string(std::string_view str)
{
    return std::string(str);
}

PluginAdapter::PluginAdapter(std::shared_ptr<plugin_support::PluginCommunicatorWrapper> communicator) : mCommunicator(communicator)
{
}

std::string PluginAdapter::send(Task &task)
{
    std::string name = make_string((task.name()));
    std::string notes = make_string((task.notes()));
    std::string date = make_string((task.date()));
    std::string time = make_string((task.time()));
    std::vector<std::string> attendees ;
    std::string mail = make_string((task.email()));
    if(mail != "")
        attendees.push_back(mail);
    std::string id;
    if(mCommunicator->add(name,notes,date,time,attendees,id) == PluginApiErrorCodes::NoError)
    {
        return id;
    }
     return "";
}


bool PluginAdapter::update(Task &task)
{
    std::string name = make_string((task.name()));
    std::string notes = make_string((task.notes()));
    std::string date = make_string((task.date()));
    std::string time = make_string((task.time()));
    std::vector<std::string> attendees {make_string((task.email()))};
    std::string id = make_string((task.id()));
    return mCommunicator->update(id,name,notes,date,time,attendees) == PluginApiErrorCodes::NoError;
}


bool PluginAdapter::remove(std::string id)
{
    return mCommunicator->remove(id) == PluginApiErrorCodes::NoError;
}

bool PluginAdapter::connect()
{
    return mCommunicator->connect() == PluginApiErrorCodes::NoError;
}