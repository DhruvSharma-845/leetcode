#include <vector>

class Solution {
public:
    int countNegatives(std::vector<std::vector<int>>& grid) {
        
        auto totalCol = static_cast<int>(grid[0].size());
        auto row = int{0};
        auto col = static_cast<int>(grid[0].size() - 1);

        int negativesCount = 0;
        while(row < grid.size()) {
            while(col >= 0 && grid[row][col] < 0) {
                col--;
            }
            negativesCount += (totalCol - col - 1);
            row++;
        }
        return negativesCount;
    }
};