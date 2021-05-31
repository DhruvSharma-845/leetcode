#include <iostream>
#include <vector>
#include <set>

class Solution {
public:
    int maximumUniqueSubarray(std::vector<int>& nums) {
        auto left = int{0};
        auto right = int{0};
        std::set<int> elems;

        auto sum = int{0};
        auto maxSum = int{-1};
        for (; right < nums.size();) {
            if(elems.find(nums[right]) == elems.end()) {
                elems.insert(nums[right]);
            }
            else {
                while(nums[left] != nums[right]) {
                    elems.erase(nums[left]);
                    sum -= nums[left];
                    left++;
                }
                sum -= nums[left];
                left++;
            }
            sum += nums[right];
            if(sum > maxSum) {
                maxSum = sum;
            }
            right++;
        }
        return maxSum;
    }
};