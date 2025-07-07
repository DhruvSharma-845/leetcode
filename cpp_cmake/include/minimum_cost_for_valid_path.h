//
// Created by Dhruv Sharma on 29/06/25.
//

#ifndef MINIMUM_COST_FOR_VALID_PATH_H
#define MINIMUM_COST_FOR_VALID_PATH_H

#include <vector>
#include <limits>

//#include <iostream>

class Solution {
public:
    int minCost(std::vector<std::vector<int>>& grid) {

        int nRows = grid.size();
        int nCols = grid[0].size();

        std::vector<std::vector<int>> dpTable(nRows, std::vector<int>(nCols, std::numeric_limits<int>::max()));
        dpTable[0][0] = 0;

        std::vector<int> xIncr{1, 0, -1, 0};
        std::vector<int> yIncr{0, -1, 0, 1};
        std::vector<int> sign{2, 3, 1, 4}; // direction from new to current

        for (int k = 0; k < nRows * nCols; ++k) {
            //std::cout << k << std::endl;
            std::vector<std::vector<int>> prevState = dpTable;
            for (int i = 0; i < nRows; ++i) {
                for (int j = 0; j < nCols; ++j) {
                    for (int dir = 0; dir < 4; ++dir) {
                        int nextRow = i + yIncr[dir];
                        int nextCol = j + xIncr[dir];

                        if (nextRow >= 0 && nextRow < nRows && nextCol >= 0 && nextCol < nCols) {
                            if (dpTable[nextRow][nextCol] != std::numeric_limits<int>::max()) {
                                dpTable[i][j] = std::min(dpTable[i][j], dpTable[nextRow][nextCol] + (grid[nextRow][nextCol] == sign[dir] ? 0 : 1));
                            }
                        }
                    }
                    //std::cout << dpTable[i][j] << " ";
                }
                //std::cout << std::endl;
            }
            if(prevState == dpTable) {
                break;
            }
        }

        return dpTable[nRows - 1][nCols - 1];
    }
};

#endif //MINIMUM_COST_FOR_VALID_PATH_H
