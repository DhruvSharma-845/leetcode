#include <submatrices_that_sum_target.h>

#include <gtest/gtest.h>

TEST(Submatrices_That_Sum_Target, BasicAssertion1) {
    std::vector<std::vector<int>> matrix{{0,1,0},{1,1,1},{0,1,0}};
    Solution s;
    EXPECT_EQ(4, s.numSubmatrixSumTarget(matrix, 0));
}

TEST(Submatrices_That_Sum_Target, BasicAssertion2) {
    std::vector<std::vector<int>> matrix{{1,-1},{-1,1}};
    Solution s;
    EXPECT_EQ(5, s.numSubmatrixSumTarget(matrix, 0));
}