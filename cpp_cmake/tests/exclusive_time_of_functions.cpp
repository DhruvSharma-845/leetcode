//
// Created by Dhruv Sharma on 17/05/25.
//

#include "exclusive_time_of_functions.h"
#include "utils.h"

#include <gtest/gtest.h>

TEST(ExclusiveTimeOfFunctions, Assertion1) {
    Solution s;
    std::vector<std::string> logs{"0:start:0","0:start:2","0:end:5","1:start:6","1:end:6","0:end:7"};
    std::vector<int> exclusiveTimes = s.exclusiveTime(2, logs);

    std::vector<int> expected{7, 1};
    compareVectors(exclusiveTimes, expected);
}
