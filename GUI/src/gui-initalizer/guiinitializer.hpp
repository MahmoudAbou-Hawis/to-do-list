#ifndef GUIINITIALIZER_H
#define GUIINITIALIZER_H

#include <memory>
#include "taskstoragewrapper.hpp"

class QQmlApplicationEngine;
class AbstractCoreInitializer;


class GuiInitializer
{
    public:
        GuiInitializer(QQmlApplicationEngine * app ,
        const std::shared_ptr<AbstractCoreInitializer> &coreInit);

    private:
        TaskStorageWrapper s;
};

#endif