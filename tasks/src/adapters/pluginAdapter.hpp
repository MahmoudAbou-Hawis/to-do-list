#ifndef PLUGINADAPTER_H_
#define PLUGINADAPTER_H_

#include "abstractedCommunicationadabter.hpp"
#include "plugin-support/src/pluginhcommunicatorwrapper.hpp"
#include "task.hpp"
class PluginAdapter : public AbstractedCommunicatorAdapter
{

    public :
        PluginAdapter(std::shared_ptr<plugin_support::PluginCommunicatorWrapper> communicator);
        std::string send(Task &task) override;   
        bool update(Task &task) override ; 
        bool remove(std::string id) override ;
        bool connect() override  ;

    private:
        std::shared_ptr<plugin_support::PluginCommunicatorWrapper> mCommunicator;
};


#endif