#include "gtest/gtest.h"
#include "iterator_tests.h"
#include "counting_tests.h"

int main(int argc, char **argv) {
  ::testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}