//
// Created by Dhruv Sharma on 01/06/25.
//

#include "smooth_descent_periods.h"

#include <gtest/gtest.h>

// Demonstrate some basic assertions.
TEST(Smooth_Descent_Periods_Stock, BasicAssertions) {
    Solution s;
    std::vector<int> prices{3,2,1,4};
    EXPECT_EQ(7, s.getDescentPeriods(prices));
}
