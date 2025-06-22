//
// Created by Dhruv Sharma on 22/06/25.
//

#ifndef PUT_MARBELS_IN_BAG_H
#define PUT_MARBELS_IN_BAG_H

#include <vector>
#include <utility>
#include <algorithm>

class Solution {
    using lli = long long int;
    using matrix = std::vector<std::vector<std::pair<lli, lli>>>;
public:
    lli putMarbles(std::vector<int>& weights, int k) {
        std::vector<lli> pairSum(weights.size() - 1, 0);

        for (int i = 0; i < weights.size() - 1; ++i) {
            pairSum[i] = weights[i] + weights[i + 1];
        }

        std::sort(pairSum.begin(), pairSum.end());

        lli maxScore = weights[0] + weights[weights.size() - 1];
        lli minScore = weights[0] + weights[weights.size() - 1];
        for (int i = 0; i < k - 1; ++i) {
            minScore += pairSum[i];
            maxScore += pairSum[weights.size() - 2 - i];
        }

        return std::abs(maxScore - minScore);
    }
};

#endif //PUT_MARBELS_IN_BAG_H
