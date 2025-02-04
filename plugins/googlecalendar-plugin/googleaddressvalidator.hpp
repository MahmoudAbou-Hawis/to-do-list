#ifndef GOOGLEADDRESSVALIDATOR_H_
#define GOOGLEADDRESSVALIDATOR_H_

#include "export/pluginaddressvalidator.hpp"


class GoogleAddressValidator final : public PluginAddressValidator
{
   public:
   virtual PluginApiErrorCodes isValid(const char* time) const  noexcept override;
};


#endif