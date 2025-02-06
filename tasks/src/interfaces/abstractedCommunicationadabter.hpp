#ifndef ABSTRACTEDCOMMUNICATORADAPTER_H_
#define ABSTRACTEDCOMMUNICATORADAPTER_H_

#include <string>
class Task;

class AbstractedCommunicatorAdapter
{
public:
    virtual std::string send( Task &task) = 0;
    virtual bool update( Task &task) = 0;
    virtual bool remove( std::string id) = 0;
    virtual bool connect() = 0;
    virtual ~AbstractedCommunicatorAdapter(){};
};

#endif
