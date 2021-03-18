#include "c-echo.h"

#include "gtest/gtest.h"

TEST(EchoTest, HelloWorld) {
    char* test_val[3]; test_val[0] = "./c-echo"; test_val[1] = "hello"; test_val[2] = "world";
    EXPECT_EQ("hello world", echo(3,test_val));
}

TEST(EchoTest, EmptyString) {
    char* test_val[1]; test_val[0] = "./c-echo";
    EXPECT_EQ("", echo(1,test_val));
}

TEST(EchoTest, UpperCase) {
    char* test_val[3]; test_val[0] = "./c-echo"; test_val[1] = "HELLO"; test_val[2] = "WORLD";
    EXPECT_EQ("HELLO WORLD", echo(3,test_val));
}

TEST(EchoTest, RandomChar) {
    char* test_val[3]; test_val[0] = "./c-echo"; test_val[1] = "!@#$%^&*()";
    EXPECT_EQ("!@#$%^&*()", echo(2,test_val));
}

TEST(EchoTest, Numerical) {
    char* test_val[3]; test_val[0] = "./c-echo"; test_val[1] = "1234"; test_val[2] = "1.37";
    EXPECT_EQ("1234 1.37", echo(3,test_val));
}

int main(int argc, char **argv) {
  ::testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}
