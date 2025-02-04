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
    void accessToken() ;
    void refreshToken();
    std::pair<std::string, std::string> getAuthTocken() const;
    bool isExpired() const;
    std::string getRefreshToken() const;
    void authenticate();

private: 
    std::string getUserUrl() const;

private:
  std::string mUserCode;
  std::string mAccessToken;
  std::string mRefreshToken;
  std::string mTokenType;
  std::string mClientId;
  std::string mClientSecret;
  std::string mRedirectUri;
  std::string mAuthenticateCode;
  std::string mPort;
  
  std::chrono::system_clock::time_point mExpiresAt;
  HttpRequest mRequest;
  mutable std::mutex mMutex;
};

#endif