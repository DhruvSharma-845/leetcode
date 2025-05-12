//
// Created by Dhruv Sharma on 12/05/25.
//

#include "reorder_routes_to_city_zero.h"

#include <gtest/gtest.h>

TEST(ReorderRoutesToCityZero, Assertion1) {
    Solution s;
    std::vector<std::vector<int>> connections{
        {0,1},{1,3},{2,3},{4,0},{4,5}
    };
    EXPECT_EQ(s.minReorder(6, connections), 3);
}