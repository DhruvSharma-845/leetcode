//
// Created by Dhruv Sharma on 25/06/25.
//

#include "utils.h"
#include "visible_people_queue.h"

#include <gtest/gtest.h>

TEST(Visible_People_Queue, BasicAssertions) {
    Solution s;
    std::vector<int> heights{10,6,8,5,11,9};

    std::vector<int> expected{3,1,2,1,1,0};
    auto result = s.canSeePersonsCount(heights);

    compareVectors(result, expected);
}
