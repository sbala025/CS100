#ifndef __ITERATOR_TESTS_H__
#define __ITERATOR_TESTS_H__

#include "gtest/gtest.h"

#include "./lab3/base.hpp"
#include "./lab3/add.hpp"
#include "./lab3/div.hpp"
#include "./lab3/mult.hpp"
#include "./lab3/base.hpp"
#include "./lab3/op.hpp"
#include "./lab3/pow.hpp"
#include "./lab3/rand.hpp"
#include "./lab3/sub.hpp"

TEST(IteratorTest, AddTest) {
    Op* op1 = new Op(50);
    Op* op2 = new Op(220);
    Add* add = new Add(op1, op2);

    Iterator* iterator = add->create_iterator();
    iterator->first();
    EXPECT_EQ(iterator->is_done(), false);
    EXPECT_EQ(iterator->current(), op1);
    iterator->next();
    EXPECT_EQ(iterator->current(), op2);
    iterator->next();
    EXPECT_EQ(iterator->is_done(), true);
    EXPECT_EQ(iterator->current(), nullptr);
}

TEST(IteratorTest, SubTest) {
    Op* op1 = new Op(30);
    Op* op2 = new Op(20);
    Sub* sub = new Sub(op1, op2);

    Iterator* iterator = sub->create_iterator();
    iterator->first();
    EXPECT_EQ(iterator->is_done(), false);
    EXPECT_EQ(iterator->current(), op1);
    iterator->next();
    EXPECT_EQ(iterator->current(), op2);
    iterator->next();
    EXPECT_EQ(iterator->is_done(), true);
    EXPECT_EQ(iterator->current(), nullptr);
}

TEST(IteratorTest, MultTest) {
    Op* op1 = new Op(5);
    Op* op2 = new Op(4);
    Mult* mult = new Mult(op1, op2);

    Iterator* iterator = mult->create_iterator();
    iterator->first();
    EXPECT_EQ(iterator->is_done(), false);
    EXPECT_EQ(iterator->current(), op1);
    iterator->next();
    EXPECT_EQ(iterator->current(), op2);
    iterator->next();
    EXPECT_EQ(iterator->is_done(), true);
    EXPECT_EQ(iterator->current(), nullptr);
}

TEST(IteratorTest, DivTest) {
    Op* op1 = new Op(30);
    Op* op2 = new Op(2);
    Div* div = new Div(op1, op2);

    Iterator* iterator = div->create_iterator();
    iterator->first();
    EXPECT_EQ(iterator->is_done(), false);
    EXPECT_EQ(iterator->current(), op1);
    iterator->next();
    EXPECT_EQ(iterator->current(), op2);
    iterator->next();
    EXPECT_EQ(iterator->is_done(), true);
    EXPECT_EQ(iterator->current(), nullptr);
}

TEST(IteratorTest, PowTest) {
    Op* op1 = new Op(2);
    Op* op2 = new Op(3);
    Pow* pow = new Pow(op1, op2);

    Iterator* iterator = pow->create_iterator();
    iterator->first();
    EXPECT_EQ(iterator->is_done(), false);
    EXPECT_EQ(iterator->current(), op1);
    iterator->next();
    EXPECT_EQ(iterator->current(), op2);
    iterator->next();
    EXPECT_EQ(iterator->is_done(), true);
    EXPECT_EQ(iterator->current(), nullptr);
}

TEST(IteratorTest, OpTest) {
    Op* op = new Op(100);

    Iterator* iterator = op->create_iterator();
    iterator->first();
    EXPECT_EQ(iterator->is_done(), true);
    EXPECT_EQ(iterator->current(), nullptr);
}

TEST(IteratorTest, RandTest) {
    Rand* rand = new Rand();

    Iterator* iterator = rand->create_iterator();
    iterator->first();
    EXPECT_EQ(iterator->is_done(), true);
    EXPECT_EQ(iterator->current(), nullptr);
}

#endif //_ITERATOR_TESTS_H
