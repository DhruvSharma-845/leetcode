#include <vector>
#include <unordered_set>
#include <numeric>

class Solution {
private:
    void flip(std::vector<std::vector<int>>& mat, int i, int j) {
        mat[i][j] = mat[i][j] == 1 ? 0 : 1;
        if(i + 1 < mat.size()) {
            mat[i + 1][j] = mat[i + 1][j] == 1 ? 0 : 1;
        }
        if(i - 1 >= 0) {
            mat[i - 1][j] = mat[i - 1][j] == 1 ? 0 : 1;
        }
        if(j + 1 < mat[0].size()) {
            mat[i][j + 1] = mat[i][j + 1] == 1 ? 0 : 1;
        }
        if(j - 1 >= 0) {
            mat[i][j - 1] = mat[i][j - 1] == 1 ? 0 : 1;
        }
    }

    bool isZeroMatrix(const std::vector<std::vector<int>>& mat) {
        for(int i = 0; i < mat.size(); ++i) {
            for(int j = 0; j < mat[0].size(); ++j) {
                if(mat[i][j] != 0) {
                    return false;
                }
            }
        }
        return true;
    }

    int calcHash(const std::vector<std::vector<int>>& mat) {
        int hash = 0;
        int currentIndex = 0;
        for(int i = 0; i < mat.size(); ++i) {
            for(int j = 0; j < mat[0].size(); ++j) {
                hash += mat[i][j] * std::pow(2, currentIndex);
            }
        }
        return hash;
    }

    auto minFlipsUtil(std::vector<std::vector<int>> mat, std::unordered_set<int>& visited, int currentFlip) -> int {
        if(this->isZeroMatrix(mat)) {
            return currentFlip;
        }
        int minFlipsVal = std::numeric_limits<int>::max();
        for(int i = 0; i < mat.size(); ++i) {
            for(int j = 0; j < mat[0].size(); ++j) {
                flip(mat, i, j);
                int hashVal = this->calcHash(mat);
                if(visited.find(hashVal) != visited.end()) {
                    this->flip(mat, i, j);
                    continue;
                }
                visited.insert(hashVal);
                minFlipsVal = std::min(this->minFlipsUtil(mat, visited, currentFlip + 1), minFlipsVal);
                flip(mat, i, j);
                visited.erase(hashVal);
            }
        }
        return minFlipsVal;
    }
public:
    int minFlips(std::vector<std::vector<int>>& mat) {
        std::unordered_set<int> visited;
        int res = minFlipsUtil(mat, visited, 0);
        return res == std::numeric_limits<int>::max() ? -1 : res;
    }
};