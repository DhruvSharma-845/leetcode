#include <minimum_increment_subarrays.h>

#include <gtest/gtest.h>

// Demonstrate some basic assertions.
TEST(Minimum_Increment_Subarrays_To_Make_Target, BasicAssertions1) {
  Solution s;
  std::vector<int> target{1,2,3,2,1};
  EXPECT_EQ(3, s.minNumberOperations(target));
}

TEST(Minimum_Increment_Subarrays_To_Make_Target, BasicAssertions2) {
  Solution s;
  std::vector<int> target{3,1,5,4,2};
  EXPECT_EQ(7, s.minNumberOperations(target));
}