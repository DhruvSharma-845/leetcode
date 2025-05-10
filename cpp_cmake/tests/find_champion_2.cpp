//
// Created by Dhruv Sharma on 10/05/25.
//

#include "find_champion_2.h"

#include <gtest/gtest.h>

TEST(FindChamption2, Assertion1) {
    Solution s;
    std::vector<std::vector<int>> edges{
        {0,2},{1,3},{1,2}
    };
    EXPECT_EQ(s.findChampion(4, edges), -1);
}
