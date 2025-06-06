//
// Created by Dhruv Sharma on 06/06/25.
//

#ifndef STONE_GAME_VII_H
#define STONE_GAME_VII_H

#include <vector>

class Solution {
public:
    int stoneGameVII(std::vector<int>& stones) {

        std::vector<int> cumulativeSum(stones.size(), 0);
        for (int i = 0; i < stones.size(); i++) {
            cumulativeSum[i] += ((i > 0 ? cumulativeSum[i - 1]: 0) + stones[i]);
        }

        std::vector<std::vector<std::pair<int, int>>> dpTable(stones.size(), std::vector<std::pair<int, int>>(stones.size()));

        bool isAlice = (stones.size() % 2 == 0) ? false: true;
        for (int diagonal = 0; diagonal < stones.size(); ++diagonal) {
            for (int row = 0; row < stones.size() - diagonal; ++row) {
                int col = row + diagonal;
                if (isAlice) {
                    if (row == col) {
                        dpTable[row][col].first = 0;
                    }
                    else {
                        int leftRes = cumulativeSum[col] - cumulativeSum[row] + dpTable[row + 1][col].second;
                        int rightRes = cumulativeSum[col - 1] - (row > 0 ? cumulativeSum[row - 1]: 0) + dpTable[row][col - 1].second;
                        dpTable[row][col].first = std::max(leftRes, rightRes);
                    }
                }
                else {
                    if (row == col) {
                        dpTable[row][col].second = 0;
                    }
                    else {
                        int leftRes = dpTable[row + 1][col].first - (cumulativeSum[col] - cumulativeSum[row]) ;
                        int rightRes = dpTable[row][col - 1].first - (cumulativeSum[col - 1] - (row > 0 ? cumulativeSum[row - 1]: 0)) ;
                        dpTable[row][col].second = std::min(leftRes, rightRes);
                    }
                }
            }
            isAlice = !isAlice;
        }
        return dpTable[0][stones.size() - 1].first;
    }
};

#endif //STONE_GAME_VII_H
