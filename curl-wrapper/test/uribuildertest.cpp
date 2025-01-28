#include <gtest/gtest.h>
#include "uribuilder.hpp"

TEST(UriBuilderTest, TestTheReturnWithoutPathsAndQueries)
{
    UriBuilder builder("https://www.google.com");
    ASSERT_EQ(builder.uri(),"https://www.google.com");
}

TEST(UriBuilderTest, TestTheReturnWitPathwithoutQueries)
{
    UriBuilder builder("https://www.google.com");
    builder.addPath("courses");
    builder.addPath("programming C++");

    ASSERT_EQ(builder.uri(),"https://www.google.com/courses/programming%20C%2B%2B");
}


TEST(UriBuilderTest, TestTheReturnWithoutPathandWithQueries)
{
    UriBuilder builder("https://www.google.com");
    builder.addQuery("query1","query value");
    ASSERT_EQ(builder.uri(),"https://www.google.com?query1=query%20value");
}


TEST(UriBuilderTest, TestTheReturnWithtPathandWithQueries)
{
    UriBuilder builder("https://www.google.com");
    builder.addPath("programming courses");
    builder.addQuery("query1","query value").addQuery("query2","query2 value");
    ASSERT_EQ(builder.uri(),"https://www.google.com/programming%20courses?query1=query%20value&query2=query2%20value");
}



