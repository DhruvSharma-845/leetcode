#include <gtest/gtest.h>
#include <minimum_operations_to_make_array_equal.h>

TEST(Minimum_Operations_To_Make_Array_Equal, BasicAssertion1) {
    Solution s;
    std::vector<int> v1{4, 3, 1, 4};
    std::vector<int> v2{1, 3, 7, 1};
    auto res = s.minOperations(v1, v2, 3);
    ASSERT_EQ(res, 2LL);
}

TEST(Minimum_Operations_To_Make_Array_Equal, BasicAssertion2) {
    Solution s;
    std::vector<int> v1{3, 8, 5, 2};
    std::vector<int> v2{2, 4, 1, 6};
    auto res = s.minOperations(v1, v2, 1);
    ASSERT_EQ(res, -1LL);
}