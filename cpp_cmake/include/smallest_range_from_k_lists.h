//
// Created by Dhruv Sharma on 17/07/25.
//

#ifndef SMALLEST_RANGE_FROM_K_LISTS_H
#define SMALLEST_RANGE_FROM_K_LISTS_H

#include <vector>
#include <queue>
#include <limits>


class Solution {
    struct Value {
        int val;
        int listNo;
        int listIndex;
    };
public:
    std::vector<int> smallestRange(std::vector<std::vector<int>>& nums) {
        auto cmp = [](const Value& a, const Value& b) {
            return a.val > b.val;
        };
        std::priority_queue<Value, std::vector<Value>, decltype(cmp)> minpq(cmp);

        // inserting 0th element index
        int maxElement = std::numeric_limits<int>::min();
        for (int i = 0; i < nums.size(); ++i) {
            minpq.push(Value{nums[i][0], i, 0});
            maxElement = std::max(maxElement, nums[i][0]);
        }

        std::vector<int> result(2);
        result[0] = -1000000;
        result[1] = 1000000;

        while (!minpq.empty()) {
            const auto topElement = minpq.top();
            minpq.pop();

            if ((result[1] - result[0]) > (maxElement - topElement.val)) {
                result[0] = topElement.val;
                result[1] = maxElement;
            }

            // insert next element
            if (topElement.listIndex < nums[topElement.listNo].size() - 1) {
                int nextValue = nums[topElement.listNo][topElement.listIndex + 1];
                minpq.push(Value{nextValue, topElement.listNo, topElement.listIndex + 1});
                maxElement = std::max(maxElement, nextValue);
            }
            else if (topElement.listIndex == nums[topElement.listNo].size() - 1) {
                break;
            }
        }
        return result;
    }
};

#endif //SMALLEST_RANGE_FROM_K_LISTS_H
