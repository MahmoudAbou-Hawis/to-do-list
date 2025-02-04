#ifndef OWNDELETER_H_
#define OWNDELETER_H_


#include <memory>
#include "export/pluginfacade.hpp"

namespace plugin_support
{
    class own_deleter
    {
        public:
            own_deleter(PluginFacade * facade): mFacade(facade){}
            own_deleter(own_deleter && obj) :mFacade(std::move(obj.mFacade)){}

        public:
            template<typename T>
            void operator() (T * obj) noexcept
            {
                mFacade->release(obj);
            }

        private:
            PluginFacade * mFacade;
    };
} // namespace plugin_support


 



#endif