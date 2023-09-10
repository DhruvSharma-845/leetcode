#include <gtest/gtest.h>
#include "utils.h"
#include <move_all_balls_each_box.h>

TEST(Move_All_Balls_In_Each_Box, BasicAssertion1) {
    Solution s;
    auto resArr = s.minOperations(std::string{"110"});
    std::vector<int> expected{1, 1, 3};
    compareVectors(resArr, expected);
}

TEST(Move_All_Balls_In_Each_Box, BasicAssertion2) {
    Solution s;
    auto resArr = s.minOperations(std::string{"001011"});
    std::vector<int> expected{11, 8, 5, 4, 3, 4};
    compareVectors(resArr, expected);
}