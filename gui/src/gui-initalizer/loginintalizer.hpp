#ifndef LOGININTALIZER_H
#define LOGININTALIZER_H
#include <QQmlApplicationEngine>
#include "loaderwrapper.hpp"
#include <memory>

class LoginInitializer
{
    public:
        LoginInitializer(QQmlApplicationEngine *engine);
        ~LoginInitializer(){};
        
    private:
        LoaderWrapper mLoader;

};



#endif  
