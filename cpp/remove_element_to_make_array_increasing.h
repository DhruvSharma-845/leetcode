#include <vector>

class Solution {
public:
    bool canBeIncreasing(std::vector<int>& nums) {
        auto i = int{0};
        auto j = static_cast<int>(nums.size()) - 1;

        for (; i < nums.size() - 1; ++i) {
            if(nums[i] >= nums[i+1]) {
                break;
            }
        }

        for(; j > 0; --j) {
            if(nums[j] <= nums[j-1]) {
                break;
            }
        }

        if(i == nums.size() - 1) {
            return true;
        }

        if(i + 1 == j) {
            if(i == 0 || j == nums.size() - 1) {
                return true;
            }
            if(nums[i - 1] < nums[j]) {
                return true;
            }
            if(nums[i] < nums[j+1]) {
                return true;
            }
        }
        return false;
    }
};