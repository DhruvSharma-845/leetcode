//
// Created by Dhruv Sharma on 25/05/25.
//

#include "two_best_non_overlapping_events.h"

#include <gtest/gtest.h>

TEST(TwoBestNonOverlappingEvents, Assertion1) {
    Solution s;
    std::vector<std::vector<int>> events{
        {1,3,2},{4,5,2},{2,4,3}
    };
    EXPECT_EQ(s.maxTwoEvents(events), 4);
}
