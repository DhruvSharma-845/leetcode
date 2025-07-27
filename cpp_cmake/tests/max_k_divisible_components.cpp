//
// Created by Dhruv Sharma on 27/07/25.
//

#include "max_k_divisible_components.h"

#include <gtest/gtest.h>

TEST(Max_K_Divisible_Components, BasicAssertions) {
    Solution s;
    std::vector<std::vector<int>> edges{{0,2},{1,2},{1,3},{2,4}};
    std::vector<int> values{1,8,1,4,4};
    auto result = s.maxKDivisibleComponents(5, edges, values, 6);

    EXPECT_EQ(result, 2);
}
