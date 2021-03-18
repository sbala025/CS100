#include "gtest/gtest.h"

#include "op_test.hpp"
#include <random>

#include "op.hpp"
#include "mult.hpp"
#include "sub.hpp"
#include "add.hpp"
#include "pow.hpp"
#include "div.hpp"
#include "rand.hpp"
#include "base.hpp"

int main(int argc, char **argv) {
  ::testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}

TEST(OpTest, MultPos) {
    Op *v1 = new Op(7);
    Op *v2 = new Op(7);
    Base* test = new Mult(v1, v2);
    EXPECT_EQ(test->evaluate(), 49);
    EXPECT_EQ(test->stringify(), "7.000000 * 7.000000");
}

TEST(OpTest, MultNegResult) {
    Op *v1 = new Op(-5);
    Op *v2 = new Op(7);
    Base* test = new Mult(v1, v2);
    EXPECT_EQ(test->evaluate(), -35);
}

TEST(OpTest, MultZero) {
    Op *v1 = new Op(0);
    Op *v2 = new Op(7);
    Base* test = new Mult(v1, v2);
    EXPECT_EQ(test->evaluate(), 0);
}

TEST(OpTest, SubPos) {
    Op *v1 = new Op(7);
    Op *v2 = new Op(2);
    Base* test = new Sub(v1, v2);
    EXPECT_EQ(test->evaluate(), 5);
    EXPECT_EQ(test->stringify(), "7.000000 - 2.000000");
}

TEST(OpTest, SubNeg) {
    Op *v1 = new Op(-7);
    Op *v2 = new Op(2);
    Base* test = new Sub(v1, v2);
    EXPECT_EQ(test->evaluate(), -9);
}

TEST(OpTest, SubZero) {
    Op *v1 = new Op(12);
    Op *v2 = new Op(12);
    Base* test = new Sub(v1, v2);
    EXPECT_EQ(test->evaluate(), 0);
    EXPECT_EQ(test->stringify(), "12.000000 - 12.000000");
}

TEST(OpTest, AddZero) {
    Op *v1 = new Op(12);
    Op *v2 = new Op(-12);
    Base* test = new Add(v1, v2);
    EXPECT_EQ(test->evaluate(), 0);
    EXPECT_EQ(test->stringify(), "12.000000 + -12.000000");
}

TEST(OpTest, AddNegNums) {
    Op *v1 = new Op(-8);
    Op *v2 = new Op(-12);
    Base* test = new Add(v1, v2);
    EXPECT_EQ(test->evaluate(), -20);
}

TEST(OpTest, DivideWholeNum) {
    Op *v1 = new Op(12);
    Op *v2 = new Op(2);
    Base* test = new Div(v1, v2);
    EXPECT_EQ(test->evaluate(), 6);
    EXPECT_EQ(test->stringify(), "12.000000 / 2.000000");
}

TEST(OpTest, DivideDecResult) {
    Op *v1 = new Op(2);
    Op *v2 = new Op(10);
    Base* test = new Div(v1, v2);
    EXPECT_EQ(test->evaluate(), 0.2);
}

TEST(OpTest, DivideZero) {
    Op *v1 = new Op(0);
    Op *v2 = new Op(2);
    Base* test = new Div(v1, v2);
    EXPECT_EQ(test->evaluate(), 0);
}

TEST(OpTest, PowerPos) {
    Op *v1 = new Op(2);
    Op *v2 = new Op(6);
    Base* test = new Pow(v1, v2);
    EXPECT_EQ(test->evaluate(), 64);
    EXPECT_EQ(test->stringify(), "2.000000 ** 6.000000");
}

TEST(OpTest, PowerNegPower) {
    Op *v1 = new Op(2);
    Op *v2 = new Op(-3);
    Base* test = new Pow(v1, v2);
    EXPECT_EQ(test->evaluate(), .125);
}

TEST(OpTest, PowerNegResult) {
    Op *v1 = new Op(-2);
    Op *v2 = new Op(3);
    Base* test = new Pow(v1, v2);
    EXPECT_EQ(test->evaluate(), -8);
}

TEST(OpTest, RandomPos) {
   Rand *test = new Rand();
   EXPECT_LT(test->evaluate(), 100);   
}


TEST(OpTest, RandomNeg) {
   Rand *test = new Rand();
   EXPECT_LT(-1, test->evaluate());
}
	
