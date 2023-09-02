#include <gtest/gtest.h>

#include <partition_array_three_parts_equal_sum.h>

TEST(ArrayPartitioningToEqualSum, Assertions) {
    Solution s;

    std::vector<int> v1{0,2,1,-6,6,-7,9,1,2,0,1};
    ASSERT_TRUE(s.canThreePartsEqualSum(v1));

    std::vector<int> v2{0,2,1,-6,6,7,9,-1,2,0,1};
    ASSERT_FALSE(s.canThreePartsEqualSum(v2));

    std::vector<int> v3{3,3,6,5,-2,2,5,1,-9,4};
    ASSERT_TRUE(s.canThreePartsEqualSum(v3));
}