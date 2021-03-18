#include "gtest/gtest.h"
#include "operand_tests.hpp"
#include "container_tests.hpp"

// Put sorting tests below
#include "VectorContainer.hpp"
#include "listcontainer.hpp"
#include "SelectionSort.hpp"
#include "BubbleSort.hpp"

//--------------------------------------------------------------------------------------------------------------------------------------------
//BUBBLE SORT TESTS
//--------------------------------------------------------------------------------------------------------------------------------------------
TEST(BubbleSortTests, ListContainerTest) {

    // Three Operations: Multiply, Divide, Add
    auto op1 = new Op(24);
    auto op2 = new Op(3);

    auto multTree = new Mult(op1, op2);
    auto divideTree = new Div(op1, op2);
    auto addTree = new Add(op1, op2);

    ListContainer listContainer = ListContainer();
    // Add trees
    listContainer.add_element(multTree);
    listContainer.add_element(divideTree);
    listContainer.add_element(addTree);

    // Validate numbers and positions
    ASSERT_EQ(listContainer.size(), 3);
    EXPECT_EQ(listContainer.at(0)->evaluate(), 24  * 3);
    EXPECT_EQ(listContainer.at(1)->evaluate(), 24 / 3);
    EXPECT_EQ(listContainer.at(2)->evaluate(), 24 + 3);

    // Sort
    listContainer.set_sort_function(new BubbleSort());
    listContainer.sort();

    // Validate sort
    ASSERT_EQ(listContainer.size(), 3);
    EXPECT_EQ(listContainer.at(0)->evaluate(), 24 / 3);
    EXPECT_EQ(listContainer.at(1)->evaluate(), 24 + 3);
    EXPECT_EQ(listContainer.at(2)->evaluate(), 24  * 3);
}

// Same test as above w/ some slight variation
TEST(BubbleSortTests, VectorContainerTest) {

    // Three Operations: Multiply, Power, Subtract
    auto op1 = new Op(2);
    auto op2 = new Op(6);

    auto multTree = new Mult(op1, op2);
    auto powerTree = new Pow(op1, op2);
    auto subTree = new Sub(op1, op2);

    VectorContainer vectorContainer = VectorContainer();
    // Add trees
    vectorContainer.add_element(multTree);
    vectorContainer.add_element(powerTree);
    vectorContainer.add_element(subTree);

    // Validate numbers and positions
    ASSERT_EQ(vectorContainer.size(), 3);
    EXPECT_EQ(vectorContainer.at(0)->evaluate(), 12);
    EXPECT_EQ(vectorContainer.at(1)->evaluate(), 64);
    EXPECT_EQ(vectorContainer.at(2)->evaluate(), -4);

    // Sort
    vectorContainer.set_sort_function(new BubbleSort());
    vectorContainer.sort();

    // Validate sort
    ASSERT_EQ(vectorContainer.size(), 3);
    EXPECT_EQ(vectorContainer.at(0)->evaluate(), -4);
    EXPECT_EQ(vectorContainer.at(1)->evaluate(), 12);
    EXPECT_EQ(vectorContainer.at(2)->evaluate(), 64);
}

//--------------------------------------------------------------------------------------------------------------------------------------------
//SELECTION SORT TESTS
//--------------------------------------------------------------------------------------------------------------------------------------------
TEST(SelectionSort, SelectionSortVectorContainer) {
    //Muktiply
    Op* seven = new Op(7);
    Op* four = new Op(4);
    Mult* TreeA = new Mult(seven, four);
    
    //Addition
    Op* three = new Op(3);
    Op* two = new Op(2);
    Add* TreeB = new Add(three, two);

    //Subtract
    Op* ten = new Op(10);
    Op* six = new Op(6);
    Sub* TreeC = new Sub(ten, six);

    VectorContainer* container = new VectorContainer();
    container->add_element(TreeA);
    container->add_element(TreeB);
    container->add_element(TreeC);

    ASSERT_EQ(container->size(), 3);
    EXPECT_EQ(container->at(0)->evaluate(), 28);
    EXPECT_EQ(container->at(1)->evaluate(), 5);
    EXPECT_EQ(container->at(2)->evaluate(), 4);

    container->set_sort_function(new SelectionSort());
    container->sort();

    ASSERT_EQ(container->size(), 3);
    EXPECT_EQ(container->at(0)->evaluate(), 4);
    EXPECT_EQ(container->at(1)->evaluate(), 5);
    EXPECT_EQ(container->at(2)->evaluate(), 28);
}

TEST(SelectionSort, SectionSortListContainer) {
    //Multiply
    Op* negSeven = new Op(-7);
    Op* negFour = new Op(-4);
    Mult* TreeA = new Mult(negSeven, negFour);

    //Add
    Op* negThree = new Op(-3);
    Op* negTwo = new Op(-2);
    Add* TreeB = new Add(negThree, negTwo);

    //Subtract
    Op* negTen = new Op(-10);
    Op* negSix = new Op(-6);
    Sub* TreeC = new Sub(negTen, negSix);

    ListContainer* container = new ListContainer();
    container->add_element(TreeA);
    container->add_element(TreeB);
    container->add_element(TreeC);

    ASSERT_EQ(container->size(), 3);
    EXPECT_EQ(container->at(0)->evaluate(), 28);
    EXPECT_EQ(container->at(1)->evaluate(), -5);
    EXPECT_EQ(container->at(2)->evaluate(), -4);

    container->set_sort_function(new SelectionSort());
    container->sort();

    ASSERT_EQ(container->size(), 3);
    EXPECT_EQ(container->at(0)->evaluate(), -5);
    EXPECT_EQ(container->at(1)->evaluate(), -4);
    EXPECT_EQ(container->at(2)->evaluate(), 28);
}

int main(int argc, char **argv) {
  ::testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}
