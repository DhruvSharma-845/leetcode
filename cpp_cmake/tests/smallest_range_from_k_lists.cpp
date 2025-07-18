//
// Created by Dhruv Sharma on 17/07/25.
//

#include "smallest_range_from_k_lists.h"
#include "utils.h"

#include <gtest/gtest.h>

TEST(Smallest_Range_From_K_Lists, BasicAssertions) {
    Solution s;
    std::vector<std::vector<int>> grid{{4,10,15,24,26},{0,9,12,20},{5,18,22,30}};
    auto result = s.smallestRange(grid);

    std::vector<int> expected{20, 24};

    compareVectors(result, expected);
}
