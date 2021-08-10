#include <vector>
#include <utility>

class Solution {
public:
    int countServers(std::vector<std::vector<int>>& grid) {
        
        std::vector<std::pair<int, int>> serverIndices;
        
        std::vector<int> rowCount(grid.size(), 0);
        std::vector<int> colCount(grid[0].size(), 0);
        for (int i = 0; i < grid.size(); i++) {
            for (int j = 0; j < grid[0].size(); j++) {
                if(grid[i][j] == 1) {
                    rowCount[i]++;
                    colCount[j]++;
                    serverIndices.push_back(std::make_pair(i, j));
                }
            }
        }
        int totalCount = 0;
        for(auto pr: serverIndices) {
            if(rowCount[pr.first] > 1 || colCount[pr.second] > 1) {
                totalCount++;
            }
        }
        return totalCount;
    }
};