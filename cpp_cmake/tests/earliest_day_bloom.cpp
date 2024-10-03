#include <earliest_day_bloom.h>

#include <gtest/gtest.h>

// Demonstrate some basic assertions.
TEST(Earliest_Day_Bloom, BasicAssertions) {
  Solution s;
  std::vector<int> plantTime{1,4,3};
  std::vector<int> growTime{2,3,1};
  EXPECT_EQ(9, s.earliestFullBloom(plantTime, growTime));
}