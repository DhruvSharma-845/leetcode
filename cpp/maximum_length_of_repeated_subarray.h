#include <vector>
#include <algorithm>

class Solution {
public:
    int findLength(std::vector<int>& nums1, std::vector<int>& nums2) {
        int nums1Length = static_cast<int>(nums1.size());
        int nums2Length = static_cast<int>(nums2.size());
        std::vector<std::vector<int>> dpTable(nums1Length + 1, std::vector<int>(nums2Length + 1, 0));

        int ans = 0;
        for(int i = 1; i <= nums1Length; i++) {
            for (int j = 1; j <= nums2Length; j++) {
                if(nums1[i-1] == nums2[j-1]) {
                    if(i != 1 && j != 1) {
                        if(nums1[i-2] == nums2[j-2]) {
                            dpTable[i][j] = dpTable[i-1][j-1] + 1;
                        }
                        else {
                            dpTable[i][j] = 1;
                        }
                    }
                    else {
                        dpTable[i][j] = 1;
                    }
                }
                ans = std::max(ans, dpTable[i][j]);
            }   
        }
        return ans;
    }
};