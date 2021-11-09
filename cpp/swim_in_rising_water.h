#include <vector>
#include <limits>
#include <algorithm>
#include <iostream>

class Solution {
public:
    int swimInWater(std::vector<std::vector<int>>& grid) {
        
        auto rows = static_cast<int>(grid.size());
        auto cols = static_cast<int>(grid[0].size());

        auto area = rows * cols;

        std::vector<int> rowDir{-1, 0, 1, 0};
        std::vector<int> colDir{0, 1, 0, -1};

        const int MAXINT = std::numeric_limits<int>::max();


        std::vector<std::vector<int>> finalWater = std::vector<std::vector<int>>(rows, std::vector<int>(cols, MAXINT));
        finalWater[0][0] = grid[0][0];
        for(auto index = 0; index < rows; ++index) {
            for(auto i = 0; i < rows; ++i) {
                for(auto j = 0; j < cols; ++j) {
                    if(i == 0 && j == 0) {
                        continue;
                    }
                    int minVal = MAXINT;
                    for(int d = 0; d < 4; ++d) {
                        int newRow = i + rowDir[d];
                        int newCol = j + colDir[d];
                        if(newRow >= 0 && newRow < rows && newCol >= 0 && newCol < cols) {
                            minVal = std::min(minVal, finalWater[newRow][newCol]);
                        }
                    }
                    finalWater[i][j] = ((minVal == MAXINT) ? grid[i][j] : std::max(grid[i][j], minVal));
                    //std::cout << index << "-" << i << ":" << j << "-> " << minVal << "(" << finalWater[i][j] << ")" << std::endl;
                    
                }
            }
        }
        return finalWater[rows-1][cols-1];
    }
};


/*
*   1 2 3
*     5 4
*     6 7
*/

