#include "calendaroauth.hpp"
#include <nlohmann/json.hpp>
#include "uribuilder.hpp"
#include <spdlog/spdlog.h>
#include "httprequest.hpp"

CalendarOauth::CalendarOauth(std::string clientId, std::string clientSecret,
                             std::string redirectUri) : mClientId(std::move(clientId)),
                                                        mClientSecret(std::move(clientSecret)), mRedirectUri(std::move(redirectUri))
{
}
CalendarOauth::CalendarOauth(std::string clientId, std::string clientSecret,
                             std::string redirectUri, std::string refreshToken) : mClientId(std::move(clientId)), mClientSecret(std::move(clientSecret)),
                                                                                  mRedirectUri(std::move(redirectUri)), mRefreshToken(std::move(refreshToken))
{
}

void CalendarOauth::accessToken(const std::string &userCode, std::string &port)
{
    UriBuilder builder("");
    std::string usercode = userCode;
    builder.addQuery("code", usercode)
        .addQuery("client_id", mClientId)
        .addQuery("client_secret", mClientSecret)
        .addQuery("redirect_uri", REDIRECT_URL + port)
        .addQuery("grant_type", "authorization_code");

    HttpRequest mRequest;
    std::string uri = builder.uri();
    auto [code, res] = mRequest.post(
        "https://www.googleapis.com/oauth2/v4/token", uri.substr(1, uri.size() - 1),
        {{"Content-Type", "application/x-www-form-urlencoded"}});

    auto logger = spdlog::get("calendar_logger");
    if (HttpCode::OK != code)
    {
        logger->error(
            "Failed to get access token loadAccessToken with code: {}, response: "
            "{}",
            static_cast<int>(code), res.c_str());
        throw std::runtime_error("Failed to get access token");
    }
    logger->info("Aceess token successfully loaded");
    auto body = nlohmann::json::parse(res);
    mAccessToken = body.at("access_token");
    mRefreshToken = body.at("refresh_token");
    mTokenType = body.at("token_type");
    mExpiresAt = std::chrono::system_clock::now() +
                 std::chrono::seconds(body.at("expires_in"));
}

void CalendarOauth::refreshToken(const std::string &userCode)
{
    UriBuilder builder("");
    builder.addQuery("refresh_token", mRefreshToken)
        .addQuery("client_id", mClientId)
        .addQuery("client_secret", mClientSecret)
        .addQuery("grant_type", "refresh_token");
    HttpRequest mRequest;
    std::string uri = builder.uri();
    auto [code, res] = mRequest.post(
        "https://www.googleapis.com/oauth2/v4/token", uri.substr(1, uri.size() - 1),
        {{"Content-Type", "application/x-www-form-urlencoded"}});
    auto logger = spdlog::get("calendar_logger");
    if (code != HttpCode::OK)
    {
        logger->error(
            "Failed to refresh token with code: {}, response: "
            "{}",
            static_cast<int>(code), res.c_str());
        throw std::runtime_error("Failed to refresh token");
    }
    auto body = nlohmann::json::parse(res);
    mAccessToken = body.at("access_token");
    mExpiresAt = std::chrono::system_clock::now() +
                 std::chrono::seconds(body.at("expires_in"));
    mTokenType = body.at("token_type");
}

std::pair<std::string, std::string> CalendarOauth::getAuthTocken() const
{
    [[maybe_unused]] std::lock_guard<std::mutex> guard(mMutex);
    return {"Authorization " + mTokenType + " ", mAccessToken};
}

bool CalendarOauth::isExpired() const
{
    [[maybe_unused]] std::lock_guard<std::mutex> guard(mMutex);
    return std::chrono::system_clock::now() >= mExpiresAt;
}

std::string CalendarOauth::getUserUrl(std::string &port) const
{
    UriBuilder builder("https://accounts.google.com/o/oauth2/v2/auth");
    builder.addQuery("client_id", mClientId)
        .addQuery("redirect_uri", REDIRECT_URL + port)
        .addQuery("response_type", "code")
        .addQuery("scope", "https://www.googleapis.com/auth/calendar")
        .addQuery("access_type", "offline")
        .addQuery("prompt", "consent");
    return builder.uri();
}

std::string CalendarOauth::getRefreshToken() const
{
    [[maybe_unused]] std::lock_guard<std::mutex> guard(mMutex);
    return mRefreshToken;
}
