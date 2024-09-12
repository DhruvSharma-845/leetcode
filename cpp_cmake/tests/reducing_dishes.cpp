#include <gtest/gtest.h>

#include <reducing_dishes.h>

TEST(Reducing_Dishes, Assertions) {
    Solution s;

    std::vector<int> v1{-1,-8,0,5,-9};
    ASSERT_EQ(s.maxSatisfaction(v1), 14);

    std::vector<int> v2{4,3,2};
    ASSERT_EQ(s.maxSatisfaction(v2), 20);

    std::vector<int> v3{-1,-4,-5};
    ASSERT_EQ(s.maxSatisfaction(v3), 0);
}