#ifndef __UTILS_H__
#define __UTILS_H__ 

#include <vector>
#include <gtest/gtest.h>


template <typename T>
auto compareVectors(const std::vector<T>& actual, const std::vector<T>& expected) -> void {
    ASSERT_EQ(actual.size(), expected.size());
    for(auto i = 0; i < expected.size(); ++i) {
        EXPECT_EQ(actual[i], expected[i]);
    }
}

template <typename T>
auto compareMatrix(const std::vector<std::vector<T>>& actual, const std::vector<std::vector<T>>& expected) -> void {
    ASSERT_EQ(actual.size(), expected.size());
    for(auto i = 0; i < expected.size(); ++i) {
        compareVectors(actual[i], expected[i]);
    }
}

#endif // __UTILS_H__