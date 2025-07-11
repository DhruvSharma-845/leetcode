//
// Created by Dhruv Sharma on 11/07/25.
//

#ifndef MINIMUM_OBSTACLE_REMOVAL_REACH_CORNER_H
#define MINIMUM_OBSTACLE_REMOVAL_REACH_CORNER_H

#include <vector>
#include <deque>
#include <utility>
#include <limits>

class Solution {
    using Cell = std::pair<int, int>;
public:
    int minimumObstacles(std::vector<std::vector<int>>& grid) {
        int rows = grid.size();
        int cols = grid[0].size();
        std::vector<int> rowIncr{0, 1, 0, -1};
        std::vector<int> colIncr{1, 0, -1, 0};

        std::vector<std::vector<int>> dpTable(rows, std::vector<int>(cols, std::numeric_limits<int>::max()));
        std::deque<Cell> deq;

        deq.push_back(std::make_pair(0, 0));
        dpTable[0][0] = 0;

        while (!deq.empty()) {
            const auto cell = deq.front();
            deq.pop_front();

            for (int i = 0; i < rowIncr.size(); ++i) {
                int nextRow = cell.first + rowIncr[i];
                int nextCol = cell.second + colIncr[i];

                if (nextRow >= 0 && nextRow < rows && nextCol >= 0 && nextCol < cols && dpTable[nextRow][nextCol] == std::numeric_limits<int>::max()) {
                    if (grid[nextRow][nextCol] == 0) {
                        deq.push_front(std::make_pair(nextRow, nextCol));
                        if (dpTable[cell.first][cell.second] != std::numeric_limits<int>::max()) {
                            dpTable[nextRow][nextCol] = dpTable[cell.first][cell.second];
                        }
                    }
                    else if (grid[nextRow][nextCol] == 1) {
                        deq.push_back(std::make_pair(nextRow, nextCol));
                        if (dpTable[cell.first][cell.second] != std::numeric_limits<int>::max()) {
                            dpTable[nextRow][nextCol] = dpTable[cell.first][cell.second] + 1;
                        }
                    }
                }
            }
        }
        return dpTable[rows - 1][cols - 1];
    }
};

#endif //MINIMUM_OBSTACLE_REMOVAL_REACH_CORNER_H
