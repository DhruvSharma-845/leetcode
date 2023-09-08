#include <keep_city_skyline.h>
#include <gtest/gtest.h>

TEST(Keep_City_Skyline, BasicAssertion1) {
    std::vector<std::vector<int>> city{
        {3,0,8,4},
        {2,4,5,7},
        {9,2,6,3},
        {0,3,1,0}
    };
    Solution s;
    ASSERT_EQ(35, s.maxIncreaseKeepingSkyline(city));
}

TEST(Keep_City_Skyline, BasicAssertion2) {
    std::vector<std::vector<int>> city{
        {0,0,0},
        {0,0,0},
        {0,0,0}
    };
    Solution s;
    ASSERT_EQ(0, s.maxIncreaseKeepingSkyline(city));
}