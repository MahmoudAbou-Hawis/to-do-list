#ifndef GOOGLECALENDARFACADE_H_
#define GOOGLECALENDARFACADE_H_

#include <memory>
#include "googleaddressvalidator.hpp"
#include "export/pluginfacade.hpp"


class GoogleConnectionInfo;
class GoogleCalenderCommunicator;
class GoogleAddressValidator;

class GoogleCalendarFacade final : public PluginFacade
{
public:
    GoogleCalendarFacade() ;
   virtual PluginCommunicator* makeCommunicator() noexcept override;
   virtual const PluginAddressValidator* getAddressValidator()
      const noexcept override;
   virtual const char* getId() const noexcept override;

 public:
  virtual void release(PluginCommunicator* comm) noexcept override;

  private:
    std::unique_ptr<const GoogleAddressValidator> mGoogleAddressValidator;
};


#endif