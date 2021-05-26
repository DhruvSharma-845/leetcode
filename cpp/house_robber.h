#include <iostream>
#include <vector>
#include <algorithm>

class Solution {
public:
    int rob(std::vector<int>& nums) {
        std::vector<int> table(nums.size(), 0);
        table[0] = nums[0];
        for (size_t i = 1; i < nums.size(); i++) {
            auto withCurrentHouse = nums[i] + (i > 1 ? table[i-2]: 0);
            auto withoutCurrentHouse = table[i-1];
            table[i] = std::max(withCurrentHouse, withoutCurrentHouse);
        }
        return table[nums.size() - 1];
    }
};