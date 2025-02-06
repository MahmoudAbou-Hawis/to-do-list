#include "calendaraouth.hpp"
#include <nlohmann/json.hpp>
#include "uribuilder.hpp"
#include <spdlog/spdlog.h>
#include "httprequest.hpp"
#include <boost/asio.hpp>
#include <iostream>
#include <memory>
#include <spdlog/sinks/rotating_file_sink.h>

using Socket   = std::unique_ptr<boost::asio::ip::tcp::socket>;
using Acceptor = std::unique_ptr<boost::asio::ip::tcp::acceptor>;
using IoServicePtr = std::shared_ptr<boost::asio::io_service>;




int get_free_port()
{
    using namespace boost::asio;
    io_service io;
    ip::tcp::acceptor acceptor(io, ip::tcp::endpoint(ip::tcp::v4(), 0));
    return acceptor.local_endpoint().port();
}


std::pair<Socket,Acceptor> make_socket(IoServicePtr io,int port)
{
    using namespace boost::asio;
    return std::make_pair(
        std::make_unique<ip::tcp::socket>(*io),
        std::make_unique<ip::tcp::acceptor>(*io, ip::tcp::endpoint(ip::tcp::v4(), port)));
}


std::string getGoogleAouthRespose(Socket soc , Acceptor acc)
{
    using namespace boost::asio;
    acc->accept(*soc);
    char data[1024];
    soc->read_some(buffer(data));
    boost::asio::write(*soc, boost::asio::buffer("The process was completed successfully. go to app") );
    soc->shutdown(socket_base::shutdown_type::shutdown_both);
    return std::string(data);
}


std::string getAouthCode(std::string &response)
{
    std::string key = "";
    bool eq = false;
    for(auto &i : response)
    {
        if(i == '&') break;
        if(eq) key += i;
        if(i == '=') eq = true;
    }
    return key;
}



std::string get_platform_command()
{
    #ifdef _WIN32
               return "start ";
    #elif __linux__
            return "xdg-open ";
    #endif
}

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


void CalendarOauth::accessToken()
{
    UriBuilder builder("");
    builder.addQuery("code", mAuthenticateCode)
        .addQuery("client_id", mClientId)
        .addQuery("client_secret", mClientSecret)
        .addQuery("redirect_uri", REDIRECT_URL + mPort)
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

void CalendarOauth::refreshToken()
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

std::string CalendarOauth::getUserUrl() const
{
    UriBuilder builder("https://accounts.google.com/o/oauth2/v2/auth");
    builder.addQuery("client_id", mClientId)
        .addQuery("redirect_uri", REDIRECT_URL + mPort)
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

void CalendarOauth::authenticate()
{
    int port = get_free_port();
    mPort = std::to_string(port);
    IoServicePtr io = std::make_shared<boost::asio::io_service>();
    auto [soc , acc] = make_socket(io,port);
    std::string command  = get_platform_command();
    std::string auth_url = getUserUrl();
    command.append("'").append(auth_url).append("'");
    std::system(command.c_str());
    std::string response = getGoogleAouthRespose(std::move(soc),std::move(acc));
    mAuthenticateCode = getAouthCode(response);
    accessToken();
}