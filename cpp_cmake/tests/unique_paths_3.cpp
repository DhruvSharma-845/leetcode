#include <vector>
#include <gtest/gtest.h>

#include <unique_paths_3.h>

TEST(Unique_Paths_3, Assertion1) {
    Solution s;
    std::vector<std::vector<int>> grid{{1,0,0,0},{0,0,0,0},{0,0,2,-1}};
    ASSERT_EQ(s.uniquePathsIII(grid), 2);
}

TEST(Unique_Paths_3, Assertion2) {
    Solution s;
    std::vector<std::vector<int>> grid{{0,1},{2, 0}};
    ASSERT_EQ(s.uniquePathsIII(grid), 0);
}