//
// Created by Dhruv Sharma on 29/05/25.
//

#include "minimum_maximum_products.h"

#include <gtest/gtest.h>

// Demonstrate some basic assertions.
TEST(Minimum_Maximum_Products, BasicAssertions) {
    Solution s;
    std::vector<int> quant{11, 6};
    EXPECT_EQ(3, s.minimizedMaximum(6, quant));
}
