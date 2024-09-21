#include <cherry_pickup_II.h>

#include <gtest/gtest.h>

// Demonstrate some basic assertions.
TEST(Cherry_Pickup_II, BasicAssertions) {
  Solution s;
  std::vector<std::vector<int>> matrix{{3,1,1},{2,5,1},{1,5,5},{2,1,1}};
  EXPECT_EQ(24, s.cherryPickup(matrix));
}