#include <vector>

class Solution {
private:
    const std::vector<std::pair<int, int>> directionDiff{{0, 1}, {1, 0}, {0, -1}, {-1, 0}};

    void uniquePathsUtil(
        const std::vector<std::vector<int>>& grid,
        std::vector<std::vector<bool>>& visited,
        std::pair<int, int> current,
        int& totalPaths) {
            int rows = grid.size();
            int columns = grid[0].size();
            if(grid[current.first][current.second] == 2) {
                for(int i = 0; i < rows; ++i) {
                    for(int j = 0; j < columns; ++j) {
                        if(grid[i][j] == 0 && !visited[i][j]) {
                            return;
                        }
                    }
                }
                ++totalPaths;
                return;
            }
            visited[current.first][current.second] = true;
            for(int i = 0; i < 4; ++i) {
                int newRow = current.first + directionDiff[i].first;
                int newColumn = current.second + directionDiff[i].second;
                if(newRow >= 0 && newRow < rows && newColumn >= 0 && newColumn < columns) {
                    if(grid[newRow][newColumn] != -1 && !visited[newRow][newColumn]) {
                        uniquePathsUtil(grid, visited, std::pair<int, int>(newRow, newColumn), totalPaths);
                    }
                }
            }
            visited[current.first][current.second] = false;
        }
public:
    int uniquePathsIII(std::vector<std::vector<int>>& grid) {
        std::vector<std::vector<bool>> visited(grid.size(), std::vector<bool>(grid[0].size(), false));
        int totalPaths = 0;
        for(auto i = 0; i < grid.size(); ++i) {
            for(auto j = 0; j < grid[0].size(); ++j) {
                if(grid[i][j] == 1) {
                    uniquePathsUtil(grid, visited, std::pair<int, int>(i, j), totalPaths);
                    break;
                }
            }
        }
        return totalPaths;
    }
};