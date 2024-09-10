#include <gtest/gtest.h>
#include "utils.h"

auto compareVectors(const std::vector<int>& actual, const std::vector<int>& expected) -> void {
    ASSERT_EQ(actual.size(), expected.size());
    for(auto i = 0; i < expected.size(); ++i) {
        EXPECT_EQ(actual[i], expected[i]);
    }
}

auto compareMatrix(const std::vector<std::vector<int>>& actual, const std::vector<std::vector<int>>& expected) -> void {
    ASSERT_EQ(actual.size(), expected.size());
    for(auto i = 0; i < expected.size(); ++i) {
        compareVectors(actual[i], expected[i]);
    }
}