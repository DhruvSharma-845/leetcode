//
// Created by Dhruv Sharma on 29/06/25.
//

#include "../include/minimum_cost_for_valid_path.h"

#include <gtest/gtest.h>

TEST(Minimum_Cost_For_Valid_Path, BasicAssertions) {
    Solution s;
    std::vector<std::vector<int>> grid{{1,1,1,1},{2,2,2,2},{1,1,1,1},{2,2,2,2}};
    auto result = s.minCost(grid);

    EXPECT_EQ(result, 3);
}
