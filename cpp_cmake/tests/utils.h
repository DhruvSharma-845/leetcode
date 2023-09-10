#include <gtest/gtest.h>
#include <vector>

auto compareVectors(const std::vector<int>& actual, const std::vector<int>& expected) {
    ASSERT_EQ(actual.size(), expected.size());
    for(auto i = 0; i < expected.size(); ++i) {
        EXPECT_EQ(actual[i], expected[i]);
    }
}