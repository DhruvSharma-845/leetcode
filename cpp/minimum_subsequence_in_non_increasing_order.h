#include <vector>
#include <algorithm>
#include <numeric>

class Solution {
public:
    std::vector<int> minSubsequence(std::vector<int>& nums) {
        std::sort(nums.begin(), nums.end());

        int sum = 0;
        sum = std::accumulate(nums.begin(), nums.end(), sum);

        int currentSum = 0;
        std::vector<int> subsequence;
        for(int i = nums.size() - 1; i >= 0; --i) {
            int tempSum = currentSum + nums[i];
            subsequence.push_back(nums[i]);   
            if(tempSum <= sum - tempSum) {
                currentSum = tempSum;
            }
            else {
                break;
            }
        }

        return subsequence;
    }
};