//
// Created by Dhruv Sharma on 01/06/25.
//

#ifndef SMOOTH_DESCENT_PERIODS_H
#define SMOOTH_DESCENT_PERIODS_H

#include <vector>

using ll = long long;
class Solution {
public:
    ll getDescentPeriods(std::vector<int>& prices) {
        int start = 0;

        ll total = 0;
        int end = 0;
        ll countOfContiguous = 0;
        while (end < prices.size()) {
            if (start == end || prices[end] == (prices[end - 1] - 1)) {
                ++countOfContiguous;
                total += countOfContiguous;
                ++end;
            }
            else {
                countOfContiguous = 0;
                start = end;
            }
        }
        return total;
    }
};


#endif //SMOOTH_DESCENT_PERIODS_H
