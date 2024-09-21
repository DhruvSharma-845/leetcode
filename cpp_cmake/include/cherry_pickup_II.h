#include <vector>
#include <algorithm>

class Solution {
private:
    std::vector<int> increments{-1, 0, 1};
public:
    int cherryPickup(std::vector<std::vector<int>>& grid) {
        std::vector<std::vector<std::vector<int>>> dpTable(grid.size(), std::vector<std::vector<int>>(grid[0].size(), std::vector<int>(grid[0].size(), -1)));

        for(int row = 0; row < grid.size(); ++row) {
            for(int firstCol = 0; firstCol < grid[0].size(); ++firstCol) {
                for(int secondCol = 0; secondCol < grid[0].size(); ++secondCol) {
                    if(row == 0) {
                        if(firstCol == 0 && secondCol == grid[0].size() - 1) {
                            dpTable[row][firstCol][secondCol] = grid[row][firstCol] + grid[row][secondCol];
                        }
                    }
                    else {
                        for(const auto& firstIncr: increments) {
                            for(const auto& secondIncr: increments) {
                                int prevFirstCol = firstCol + firstIncr;
                                int prevSecondCol = secondCol + secondIncr;
                                if(prevFirstCol >= 0 && prevFirstCol < grid[0].size() && prevSecondCol >= 0 && prevSecondCol < grid[0].size()) {
                                    if(dpTable[row - 1][prevFirstCol][prevSecondCol] != -1) {
                                        dpTable[row][firstCol][secondCol] = std::max(
                                            dpTable[row][firstCol][secondCol], 
                                            dpTable[row - 1][prevFirstCol][prevSecondCol] + grid[row][firstCol] + (firstCol == secondCol ? 0 : grid[row][secondCol]));
                                    }
                                }
                            }
                        }
                    }
                }
            }
        }
        int maxCherries = 0;
        for(int firstCol = 0; firstCol < grid[0].size(); ++firstCol) {
            for(int secondCol = 0; secondCol < grid[0].size(); ++secondCol) {
                maxCherries = std::max(maxCherries, dpTable[grid.size() - 1][firstCol][secondCol]);
            }
        }
        return maxCherries;
    }
};