//
// Created by Dhruv Sharma on 29/05/25.
//

#ifndef MINIMUM_MAXIMUM_PRODUCTS_H
#define MINIMUM_MAXIMUM_PRODUCTS_H

#include <vector>
#include <algorithm>

using lli = long long int;

class Solution {
private:
    bool checkProducts(int value, std::vector<int>& quantities, int n) {
        for (auto q: quantities) {
            n -= (q / value);
            if (q % value > 0) {
                --n;
            }
            if (n < 0) {
                return false;
            }
        }
        return true;
    }
public:
    int minimizedMaximum(int n, std::vector<int>& quantities) {
        int maxValue = 0;
        lli total = 0;
        for (auto q : quantities) {
            maxValue = std::max(maxValue, q);
            total += q;
        }

        if(quantities.size() == n) {
            return maxValue;
        }

        int quotient = total / n;
        int remainder = total % n;
        if (remainder > 0) {
            ++quotient;
        }

        if (checkProducts(quotient, quantities, n) == true) {
            return quotient;
        }

        int result = maxValue;
        int low = quotient;
        int high = maxValue;
        while (low <= high) {
            int mid = low + (high - low) / 2;
            if (checkProducts(mid, quantities, n) == true) {
                result = mid;
                high = mid - 1;
            }
            else {
                low = mid + 1;
            }
        }
        return result;
    }
};

#endif //MINIMUM_MAXIMUM_PRODUCTS_H
