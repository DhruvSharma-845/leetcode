#include <vector>

class Solution {
    using lli = long long int;
public:
    long long minOperations(std::vector<int>& nums1, std::vector<int>& nums2, int k) {
        auto addOperations = lli{0};
        auto subtractOperations = lli{0};
        for(auto i = 0; i < nums1.size(); ++i) {
            if(nums2[i] > nums1[i]) {
                if(k != 0 && (nums2[i] - nums1[i]) % k == 0) {
                    addOperations += (nums2[i] - nums1[i]) / k;
                }
                else {
                    return -1LL;
                }
            }
            else if(nums1[i] > nums2[i]) {
                if(k != 0 && (nums1[i] - nums2[i]) % k == 0) {
                    subtractOperations += (nums1[i] - nums2[i]) / k;
                }
                else {
                    return -1LL;
                }
            }
        }
        if(addOperations != subtractOperations) {
            return -1LL;
        }
        return addOperations;
    }
};