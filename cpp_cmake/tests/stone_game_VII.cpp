//
// Created by Dhruv Sharma on 06/06/25.
//

#include "stone_game_VII.h"

#include <gtest/gtest.h>

// Demonstrate some basic assertions.
TEST(Stone_Game_VII, BasicAssertions) {
    Solution s;
    std::vector<int> stones{5,3,1,4,2};
    EXPECT_EQ(6, s.stoneGameVII(stones));
}
