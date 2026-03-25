//
// Created by David PROSPÉRIN on 16/03/2026.
//

#include "Calculator.h"
#include <gtest/gtest.h>

TEST(CalculatorFactorialTest, ZeroValue) {
    Calculator calc;
    EXPECT_EQ(1, calc.factorielle(0));
}

TEST(CalculatorFactorialTest, StandardValues) {
    Calculator calc;
    EXPECT_EQ(1, calc.factorielle(1));
    EXPECT_EQ(120, calc.factorielle(5));
}

TEST(CalculatorFactorialTest, divisionWith2Double) {
    Calculator calc;
    EXPECT_NEAR(2.333, calc.div(7, 3), 0.001);
}

TEST(CalculatorFactorialTest, divisionWithZero) {
    Calculator calc;
    ASSERT_EXIT(calc.div(7, 0), ::testing::ExitedWithCode(255), "Error: Division by 0 not possible");
}