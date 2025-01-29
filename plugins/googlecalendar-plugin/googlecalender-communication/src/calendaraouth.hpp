#ifndef CALENDERTOCKENMANGER_HPP
#define CALENDERTOCKENMANGER_HPP

#include <chrono>
#include <mutex>
#include "httprequest.hpp"
#include <string>



class CalendarOauth
{
public:
    CalendarOauth(std::string clientId,
               std::string clientSecret,
               std::string redirectUri);

    CalendarOauth(std::string clientId,
               std::string clientSecret,
               std::string redirectUri,
               std::string refreshToken);

public:
    void accessToken(const std::string& userCode,std::string &port) ;
    void refreshToken(const std::string& userCode);
    std::pair<std::string, std::string> getAuthTocken() const;
    bool isExpired() const;
    std::string getRefreshToken() const;

private:

  std::string mUserCode;
  std::string mAccessToken;
  std::string mRefreshToken;
  std::string mTokenType;

  std::chrono::system_clock::time_point mExpiresAt;
  HttpRequest mRequest;
  mutable std::mutex mMutex;
};

#endif