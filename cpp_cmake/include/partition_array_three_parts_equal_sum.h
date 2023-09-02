#pragma once

#include <vector>
#include <numeric>

class Solution {
public:
    bool canThreePartsEqualSum(std::vector<int>& arr) {
        auto sumOfElements = std::accumulate(arr.begin(), arr.end(), 0);
        auto requiredSum = sumOfElements / 3;

        auto currentSum = int{0};
        auto partitionCount = int{0};

        int index = 0;
        for (; index < arr.size(); ++index) {
            currentSum += arr[index];
            if(currentSum == requiredSum) {
                ++partitionCount;
                currentSum = 0;
                if(partitionCount == 2) {
                    ++index;
                    break;
                }
            }
        }
        if(index < arr.size()) {
            ++partitionCount;
            for(; index < arr.size(); ++index) {
                currentSum += arr[index];
            }
        }
        return (partitionCount == 3 && currentSum == requiredSum ? true: false);
    }
};