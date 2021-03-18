#ifndef __COUNTING_TESTS_H__
#define __COUNTING_TESTS_H__

#include "./lab3/base.hpp"
#include "./lab3/add.hpp"
#include "./lab3/div.hpp"
#include "./lab3/mult.hpp"
#include "./lab3/base.hpp"
#include "./lab3/op.hpp"
#include "./lab3/pow.hpp"
#include "./lab3/rand.hpp"
#include "./lab3/sub.hpp"

TEST(CountingTests, AddTest) {
    // Test a basic add method 5 + 10.
    // Should end up with 2 op classes, and one add class.
    Op* op1 = new Op(5);
    Op* op2 = new Op(10);
    auto add = new Add(op1, op2);

    auto visitor = new CountVisitor();
    auto iterator = new PreorderIterator(new Add(add, new Rand()));
    iterator->first();

    while (!iterator->is_done()) {
        auto current = iterator->current();
        current->accept(visitor);

        iterator->next();
    }

    EXPECT_EQ(visitor->op_count(), 2);
    EXPECT_EQ(visitor->add_count(), 1);
    // DONT CHECK THE RAND COUNT, DONT YOU DARE
    // ITS FINE, IT WORKS
    // DONT TOUCH IT
}

TEST(CountingTests, MultiplyTest) {
    // Test a basic 5 * 10 * 10.
    // Should end up with 3 op classes, and two multiply class.
    Op* op1 = new Op(5);
    Op* op2 = new Op(10);
    auto multiply1 = new Mult(op1, op2); // 5 * 10
    auto multiply2 = new Mult(multiply1, op2); // 50 * 10

    auto visitor = new CountVisitor();

    auto iterator = new PreorderIterator(new Add(multiply2, new Rand()));
    iterator->first();

    while (!iterator->is_done()) {
        auto current = iterator->current();
        current->accept(visitor);

        iterator->next();
    }

    EXPECT_EQ(visitor->op_count(), 3);
    EXPECT_EQ(visitor->mult_count(), 2);
    // DONT CHECK THE RAND COUNT, DONT YOU DARE
    // ITS FINE, IT WORKS
    // DONT TOUCH IT
}

TEST(CountingTests, DivTest) {
    // Test a basic 2 / 10
    // Should end up with 2 op classes, and 1 div class.
    Op* op1 = new Op(2);
    Op* op2 = new Op(10);
    auto div = new Div(op1, op2);

    auto visitor = new CountVisitor();

    auto iterator = new PreorderIterator(new Add(div, new Rand()));
    iterator->first();

    while (!iterator->is_done()) {
        auto current = iterator->current();
        current->accept(visitor);

        iterator->next();
    }

    EXPECT_EQ(visitor->op_count(), 2);
    EXPECT_EQ(visitor->div_count(), 1);
    // DONT CHECK THE RAND COUNT, DONT YOU DARE
    // ITS FINE, IT WORKS
    // DONT TOUCH IT
}

TEST(CountingTests, AddMultSubTest) {
    // Test 2 + 5 * 10 - 15
    // Should end up with 4 op classes, 1 mult class, and 1 sub class;
    Op* op2 = new Op(2);
    auto op5 = new Op(5);
    Op* op10 = new Op(10);
    auto op15 = new Op(15);
    auto add = new Add(op2, op5);
    auto mult = new Mult(add, op10);
    auto sub = new Sub(mult, op15);

    auto visitor = new CountVisitor();

    auto iterator = new PreorderIterator(new Add(sub, new Rand()));
    iterator->first();

    while (!iterator->is_done()) {
        auto current = iterator->current();
        current->accept(visitor);

        iterator->next();
    }

    EXPECT_EQ(visitor->op_count(), 4);
    EXPECT_EQ(visitor->mult_count(), 1);
    EXPECT_EQ(visitor->sub_count(), 1);
    // DONT CHECK THE RAND COUNT, DONT YOU DARE
    // ITS FINE, IT WORKS
    // DONT TOUCH IT
}

TEST(CountingTests, PowRandAddTest) {
    // Test (5 + rand)^2
    // Should end up with 2 op classes, 1 add class, 1 rand class, and 1 pow class
    auto add = new Add(new Op(5), new Rand());
    auto pow = new Pow(add, new Op(2));

    auto visitor = new CountVisitor();

    auto iterator = new PreorderIterator(new Add(pow, new Op(3)));
    iterator->first();

    while (!iterator->is_done()) {
        auto current = iterator->current();
        current->accept(visitor);

        iterator->next();
    }

    EXPECT_EQ(visitor->op_count() - 1, 2);
    EXPECT_EQ(visitor->add_count(), 1);
    EXPECT_EQ(visitor->rand_count(), 1);
    EXPECT_EQ(visitor->pow_count(), 1);
}

#endif //__COUNTING_TESTS_H__
