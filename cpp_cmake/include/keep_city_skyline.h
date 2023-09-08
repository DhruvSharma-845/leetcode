#include <vector>
#include <algorithm>

class Solution {
public:
    int maxIncreaseKeepingSkyline(std::vector<std::vector<int>>& grid) {
        std::vector<int> colMaxs(grid[0].size(), 0);
        std::vector<int> rowMaxs(grid.size(), 0);

        for (auto i = 0; i < grid.size(); ++i) {
            for (auto j = 0; j < grid[0].size(); ++j) {
                rowMaxs[i] = std::max(rowMaxs[i], grid[i][j]);
                colMaxs[j] = std::max(colMaxs[j], grid[i][j]);
            }
        }
        
        int maxSum = 0;
        for (auto i = 0; i < grid.size(); ++i) {
            for (auto j = 0; j < grid[0].size(); ++j) {
                maxSum += (std::min(rowMaxs[i], colMaxs[j]) - grid[i][j]);
            }
        }
        return maxSum;
    }
};