#include <vector>
#include <gtest/gtest.h>
#include "utils.h"

#include <build_matrix_with_conditions.h>

TEST(Build_Matrix_With_Conditions, Assertion1) {
    Solution s;
    std::vector<std::vector<int>> rowConditions{{1,2},{3,2}};
    std::vector<std::vector<int>> colConditions{{2,1},{3,2}};
    auto res = s.buildMatrix(3, rowConditions, colConditions);
    compareMatrix(res, {{0,0,1}, {3,0,0}, {0,2,0}});
}
