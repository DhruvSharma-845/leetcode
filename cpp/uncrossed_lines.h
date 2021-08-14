#include <vector>
#include <algorithm>

class Solution {
public:
    int maxUncrossedLines(std::vector<int>& nums1, std::vector<int>& nums2) {
        
        std::vector<std::vector<int>> dpTable(nums1.size() + 1, std::vector<int>(nums2.size() + 1, 0));
        for(int i = 1; i <= nums1.size(); i++) {
            for (int j = 1; j <= nums2.size(); j++) {
                int x = 0;
                if(nums1[i-1] == nums2[j-1]) {
                    x = dpTable[i-1][j-1] + 1;
                }
                int y = std::max(dpTable[i][j-1], dpTable[i-1][j]);
                dpTable[i][j] = std::max(x, y);
            }
        }
        return dpTable[nums1.size()][nums2.size()];
    }
};