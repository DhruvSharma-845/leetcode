#include <iostream>
#include <vector>
#include <deque>

class Solution {
public:
    std::vector<int> mostCompetitive(std::vector<int>& nums, int k) {
        std::deque<int> q;
        q.push_back(nums[0]);
        for (auto i = 1; i <= nums.size() - k; i++) {
            if(nums[i] >= q.back()) {
                q.push_back(nums[i]);
            }
            else {
                while(!q.empty() && q.back() > nums[i]) {
                    q.pop_back();
                }
                q.push_back(nums[i]);
            }
        }
        std::cout << q.size() << std::endl;

        for (auto i = static_cast<int>(nums.size() - k + 1); i < nums.size(); i++) {
            if(q.back() > nums[i]) {
                while(q.size() > (k - (nums.size() - i)) && q.back() > nums[i]) {
                    q.pop_back();
                }
                q.push_back(nums[i]);
            }
            else {
                if(q.size() < k) {
                    q.push_back(nums[i]);
                }
            }
        }
        return std::vector<int>(q.begin(), q.begin() + k);
    }
};
