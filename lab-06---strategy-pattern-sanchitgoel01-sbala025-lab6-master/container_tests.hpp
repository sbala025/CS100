#include "gtest/gtest.h"
#include <random>
#include <string>
#include <vector>
#include <list>
#include <algorithm>
#include <iostream>
#include "sort.hpp"
#include "SelectionSort.hpp"
#include "BubbleSort.hpp"
#include "container.hpp"
#include "VectorContainer.hpp"
#include "op.hpp"
#include "mult.hpp"
#include "sub.hpp"
#include "add.hpp"
#include "pow.hpp"
#include "div.hpp"
#include "rand.hpp"
#include "base.hpp"

#include <string>
#include "listcontainer.hpp"
// Put container tests below

TEST(ListContainerTest, EmptyListSizeTest) {
    ListContainer listContainer = ListContainer();
    EXPECT_EQ(listContainer.size(), 0);
}

TEST(ListContainerTest, AtEmptyListTest) {
    ListContainer listContainer = ListContainer();

    EXPECT_EQ(listContainer.at(0), nullptr);
    EXPECT_EQ(listContainer.at(-1), nullptr);
    EXPECT_EQ(listContainer.at(1), nullptr);
}

TEST(ListContainerTest, SingleElementTest) {
    ListContainer listContainer = ListContainer();

    Op* operand = new Op(5);
    listContainer.add_element(operand);

    ASSERT_EQ(listContainer.size(), 1);
    EXPECT_EQ(listContainer.at(0), operand);
}

TEST(ListContainerTest, TripleElementTest) {
    ListContainer listContainer = ListContainer();

    auto op1 = new Op(1);
    auto op2 = new Op(2);
    auto op3 = new Op(4);

    listContainer.add_element(op1);
    listContainer.add_element(op2);
    listContainer.add_element(op3);

    ASSERT_EQ(listContainer.size(), 3);

    EXPECT_EQ(listContainer.at(0), op1);
    EXPECT_EQ(listContainer.at(1), op2);
    EXPECT_EQ(listContainer.at(2), op3);
}

TEST(ListContainerTest, SwapTest) {
    ListContainer listContainer = ListContainer();

    auto op1 = new Op(1);
    auto op2 = new Op(3);

    listContainer.add_element(op1);
    listContainer.add_element(op2);

    // Only check size, not position, since we have other tests for that
    ASSERT_EQ(listContainer.size(), 2);

    listContainer.swap(0, 1);

    // Check swap
    EXPECT_EQ(listContainer.at(0), op2);
    EXPECT_EQ(listContainer.at(1), op1);
}

TEST(ListContainerTest, PrintTest) {
    ListContainer listContainer = ListContainer();

    auto op1 = new Op(1);
    auto op2 = new Op(2);

    listContainer.add_element(op1);
    listContainer.add_element(op2);

    auto expString = op1->stringify() + '\n' + op2->stringify() + '\n';

    // Capture STD Out
    testing::internal::CaptureStdout();
    listContainer.print();
    auto resultString = testing::internal::GetCapturedStdout();

    EXPECT_EQ(expString, resultString);
}
//------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
TEST(VectorContainerTestSet, SizeTest) {
    Op* eight = new Op(8);
    Op* two = new Op(2);
    VectorContainer* test_container = new VectorContainer();
    test_container->add_element(eight);
    test_container->add_element(two);
    ASSERT_EQ(test_container->size(), 2);
    EXPECT_EQ(test_container->at(0)->evaluate(), 8);
    EXPECT_EQ(test_container->at(1)->evaluate(), 2);
}

TEST(VectorContainerTestSet, PrintTest) {
    Op* eight = new Op(8);
    Op* two = new Op(2);
    VectorContainer* test_container = new VectorContainer();
    test_container->add_element(eight);
    test_container->add_element(two);
    testing::internal::CaptureStdout();
    test_container->print();
    string output = testing::internal::GetCapturedStdout();
}

TEST(VectorContainerTestSet, SwapTest) {
    Op* seven = new Op(7);
    Op* three = new Op(3);
    VectorContainer* test_container = new VectorContainer();
    test_container->add_element(seven);
    test_container->add_element(three);
    test_container->swap(0,1);
    ASSERT_EQ(test_container->size(), 2);
    EXPECT_EQ(test_container->at(0)->evaluate(), 3);
    EXPECT_EQ(test_container->at(1)->evaluate(), 7);
}
