//
// Created by Dhruv Sharma on 09/06/25.
//

#include "rabbits_in_forest.h"

#include <gtest/gtest.h>

TEST(Rabbits_In_Forest, BasicAssertions) {
    Solution s;
    std::vector<int> ans{1,1,2};
    EXPECT_EQ(5, s.numRabbits(ans));
}
