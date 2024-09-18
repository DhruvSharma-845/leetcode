#include <minimum_flips_to_make_zero_matrix.h>

#include <gtest/gtest.h>

// Demonstrate some basic assertions.
TEST(Minimum_Flips_To_Make_Zero_Matrix, BasicAssertions) {
  Solution s;
  std::vector<std::vector<int>> matrix{{0,0}, {0,1}};
  EXPECT_EQ(3, s.minFlips(matrix));
}