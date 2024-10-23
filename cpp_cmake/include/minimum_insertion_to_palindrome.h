#include <string>
#include <cmath>
#include <vector>

class Solution {
public:
    int minInsertions(std::string s) {
        std::vector<std::vector<int>> dpTable(s.size(), std::vector<int>(s.size(), 0));

        for(int diagonal = 1; diagonal < s.size(); ++diagonal) {
            for(int row = 0; row < s.size() - diagonal; ++row) {
                int col = row + diagonal;

                if(s[row] == s[col]) {
                    dpTable[row][col] = row + 1 == col ? 0 : dpTable[row + 1][col - 1];
                }
                else {
                    dpTable[row][col] = std::min(dpTable[row + 1][col], dpTable[row][col - 1]) + 1;
                }
            }
        }
        return dpTable[0][s.size() - 1];
    }
};