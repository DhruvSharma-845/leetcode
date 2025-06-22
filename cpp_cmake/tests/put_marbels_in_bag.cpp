//
// Created by Dhruv Sharma on 22/06/25.
//

#include "put_marbels_in_bag.h"

#include <gtest/gtest.h>

TEST(Put_Marbels_In_Bag, BasicAssertions) {
    Solution s;
    std::vector<int> weights{1,4,2,5,2};
    EXPECT_EQ(s.putMarbles(weights, 3), 3);
}
