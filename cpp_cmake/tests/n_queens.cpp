#include <n_queens.h>
#include "utils.h"

#include <gtest/gtest.h>

// Demonstrate some basic assertions.
TEST(N_Queens, BasicAssertions1) {
  Solution s;
  auto res = s.solveNQueens(4);
  compareMatrix(res, {{".Q..","...Q","Q...","..Q."},{"..Q.","Q...","...Q",".Q.."}});
}