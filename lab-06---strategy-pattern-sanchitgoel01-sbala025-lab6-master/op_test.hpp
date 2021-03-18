#ifndef __OP_TEST_HPP__
#define __OP_TEST_HPP__

#include "gtest/gtest.h"

#include "op.hpp"
// Include mock operands
#include "sevenopmock.hpp"
#include "zeroopmock.hpp"
#include "negativefiveopmock.hpp"

TEST(OpTest, OpMockEvaluatePositive) {
    SevenOpMock* test = new SevenOpMock();
    EXPECT_EQ(test->evaluate(), 7.5);
}

TEST(OpTest, OpEvaluatePositive) {
    Op* test = new Op(10.5);
    EXPECT_EQ(test->evaluate(), 10.5);
}

TEST(OpTest, OpMockEvaluateZero) {
    ZeroOpMock* test = new ZeroOpMock();
    EXPECT_EQ(test->evaluate(), 0);
}

TEST(OpTest, OpEvaluateZero) {
    Op* test = new Op(0.0);
    EXPECT_EQ(test->evaluate(), 0);
}

TEST(OpTest, OpMockEvaluateNegative) {
    NegativeFiveOpMock* test = new NegativeFiveOpMock();  
    EXPECT_EQ(test->evaluate(), -5);
}

TEST(OpTest, OpEvaluateNegative) {
    Op* test = new Op(-15.5);
    EXPECT_EQ(test->evaluate(), -15.5);
}

#endif //__OP_TEST_HPP__
