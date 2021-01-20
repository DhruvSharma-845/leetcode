#include <vector>

#include <unordered_map>

class Solution {
public:
    std::vector<int> intersect(std::vector<int>& nums1, std::vector<int>& nums2) {
        
        std::unordered_map<int, int> numsCount;

        for(auto elem: nums1) {
            numsCount[elem]++;
        }

        std::vector<int> res;
        for(auto elem: nums2) {
            if(numsCount.find(elem) != numsCount.end()) {
                int count = numsCount[elem];
                if(count > 0) {
                    res.push_back(elem);
                    numsCount[elem]--;
                }
            }
        }

        return res;
    }
};