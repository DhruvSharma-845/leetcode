#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>

class Solution {
private:
    bool canMakeBagsWithMaxLimit(const std::vector<int>& nums, int ops, int maxVal) {
        for(auto elem: nums) {
            auto reqOps = (elem / maxVal) + ((elem % maxVal) > 0 ? 1 : 0) - 1;
            if(reqOps > ops) {
                return false;
            }
            else {
                ops -= reqOps;
            }
        }
        return true;
    }
public:
    int minimumSize(std::vector<int>& nums, int maxOperations) {
        auto max_it = std::max_element(nums.begin(), nums.end());

        auto low = 0;
        auto high = *max_it;
        auto ans = int{0};
        while(low <= high) {
            auto mid = low + (high - low) / 2;
            if(canMakeBagsWithMaxLimit(nums, maxOperations, mid) == true) {
                ans = mid;
                high = mid - 1;
            } 
            else {
                low = mid + 1;
            }
        }
        return ans;
    }
};