#include <n_queens_II.h>

#include <gtest/gtest.h>

TEST(N_Queens_II, BasicAssertion1) {
    Solution s;
    EXPECT_EQ(2, s.totalNQueens(4));
}