//
// Created by Dhruv Sharma on 11/07/25.
//

#include "../include/minimum_obstacle_removal_reach_corner.h"

#include <gtest/gtest.h>

TEST(Minmum_Obstacle_Removal, BasicAssertions) {
    Solution s;
    std::vector<std::vector<int>> grid{{0,1,1},{1,1,0},{1,1,0}};
    auto result = s.minimumObstacles(grid);

    EXPECT_EQ(result, 2);
}
