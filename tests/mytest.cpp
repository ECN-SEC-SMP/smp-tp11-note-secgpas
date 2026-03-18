#include "factorielle.h"
#include <gtest/gtest.h>

TEST(FactorialTest, ZeroValue) {
  EXPECT_EQ(1,factorielle(0));
}

TEST(FactorialTest, StandardValues) {
  EXPECT_EQ(1,factorielle(1));
  EXPECT_EQ(120,factorielle(5));
}

