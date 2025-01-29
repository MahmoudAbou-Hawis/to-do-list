#ifndef CALENDERTOCKENMANGER_HPP
#define CALENDERTOCKENMANGER_HPP

#include <chrono>
#include <mutex>
#include "httprequest.hpp"
#include <string>

const std::string REDIRECT_URL = "http://127.0.0.1:";

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
    std::string CalendarOauth::getUserUrl(std::string &port) const;
    bool isExpired() const;
    std::string getRefreshToken() const;

private:

  std::string mUserCode;
  std::string mAccessToken;
  std::string mRefreshToken;
  std::string mTokenType;
  std::string mClientId;
  std::string mClientSecret;
  std::string mRedirectUri;

  std::chrono::system_clock::time_point mExpiresAt;
  HttpRequest mRequest;
  mutable std::mutex mMutex;
};

#endif