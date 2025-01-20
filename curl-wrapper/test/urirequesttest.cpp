#include <gtest/gtest.h>
#include "uribuilder.hpp"
#include "httprequest.hpp"
#include <string>
#include <nlohmann/json.hpp>
#include <iostream> 
#include <regex>

TEST(HttpClientTest, GetRequestWithoutHeaders)
{
    UriBuilder builder("https://jsonplaceholder.typicode.com");
    builder.addPath("posts").addPath("1");
    HttpRequest request;
    auto [statusCode, response] =  request.get(builder.uri());

    nlohmann::json jsonResponse = nlohmann::json::parse(response);

    EXPECT_EQ(jsonResponse["id"], 1);
    EXPECT_EQ(jsonResponse["title"], "sunt aut facere repellat provident occaecati excepturi optio reprehenderit");
    EXPECT_EQ(jsonResponse["userId"], 1);
}


TEST(HttpClientTest, GetRequestWithHeaders) {
    UriBuilder builder("https://jsonplaceholder.typicode.com");
    builder.addPath("posts").addPath("1");

    HttpRequest request;
    HttpHeader myHeader = {"Accept", "application/json"};
    auto [statusCode, response] =  request.get(builder.uri(), {myHeader});


    nlohmann::json jsonResponse = nlohmann::json::parse(response);

    EXPECT_EQ(jsonResponse["id"], 1);
    EXPECT_EQ(jsonResponse["title"], "sunt aut facere repellat provident occaecati excepturi optio reprehenderit");
    EXPECT_EQ(jsonResponse["userId"], 1);
}


TEST(HttpClientTest, PostRequestWithoutHeaders) {
    UriBuilder builder("https://jsonplaceholder.typicode.com");
    builder.addPath("posts");

    std::string body = R"({"title": "foo", "body": "bar", "userId": 1})";

    HttpRequest request;
    auto [statusCode, response] = request.post(builder.uri(), body);

    ASSERT_EQ( static_cast<int>(statusCode), 201) << "Expected status code 201, but got " << static_cast<int>(statusCode);

    std::regex json_regex(R"(\{\\\"title\\\": \\\"foo\\\", \\\"body\\\": \\\"bar\\\", \\\"userId\\\": 1\})");
    std::smatch match;

    ASSERT_TRUE(std::regex_search(response, match, json_regex)) << "Wrapped JSON object not found in response";

    std::string inner_json = match[0];
    for (size_t pos = 0; (pos = inner_json.find("\\\"", pos)) != std::string::npos; pos += 1) {
        inner_json.replace(pos, 2, "\"");
    }

    auto jsonResponse = nlohmann::json::parse(inner_json);

    EXPECT_EQ(jsonResponse["title"], "foo") << "Title mismatch in response JSON";
    EXPECT_EQ(jsonResponse["body"], "bar") << "Body mismatch in response JSON";
    EXPECT_EQ(jsonResponse["userId"], 1) << "UserId mismatch in response JSON";
}


TEST(HttpClientTest, PostRequestWithHeaders) {
 UriBuilder builder("https://jsonplaceholder.typicode.com");
    builder.addPath("posts");

    std::string body = R"({"title": "foo", "body": "bar", "userId": 1})";

    HttpRequest request;

    HttpHeader myHeader = {"Content-Type", "application/json"};


    auto [statusCode, response] = request.post(builder.uri(), body, {myHeader});

    ASSERT_EQ( static_cast<int>(statusCode), 201) << "Expected status code 201, but got " << static_cast<int>(statusCode);
    
    nlohmann::json jsonResponse = nlohmann::json::parse(response);

    EXPECT_EQ(jsonResponse["title"], "foo");
    EXPECT_EQ(jsonResponse["body"], "bar");
    EXPECT_EQ(jsonResponse["userId"], 1);
}