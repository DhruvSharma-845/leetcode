#ifndef __UTILS_H__
#define __UTILS_H__ 

#include <vector>

auto compareVectors(const std::vector<int>& actual, const std::vector<int>& expected) -> void;
auto compareMatrix(const std::vector<std::vector<int>>& actual, const std::vector<std::vector<int>>& expected) -> void;

#endif // __UTILS_H__