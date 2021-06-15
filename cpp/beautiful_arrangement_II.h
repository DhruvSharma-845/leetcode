#include <iostream>
#include <vector>

class Solution {
public:
    std::vector<int> constructArray(int n, int k) {
        std::vector<int> result(n, 0);
        auto left = int{1};
        auto right = int{k+1};
        int index = 0;
        while(left < right) {
            result[index++] = left++;
            result[index++] = right--;
        }
        if(left == right) {
            result[index++] = left;
        }

        right = k + 2;
        while(index < n) {
            result[index++] = right++;
        }
        return result;
    }
};