#include <string>
#include <vector>

class Solution {
public:
    bool isMatch(std::string s, std::string p) {
        int sLength = s.length();
        int pLength = p.length();
        std::vector<std::vector<bool>> dpTable(sLength + 1, std::vector<bool>(pLength + 1, false));
        dpTable[0][0] = true;
        // for empty string
        for(int j = 1; j <= pLength; ++j) {
            if(j % 2 != 0) {
                dpTable[0][j] = false;
            }
            else {
                dpTable[0][j] = (p[j-1] == '*') && dpTable[0][j-2];
            }
            //std::cout << "i:" << i << " j:" << j << " Value: " << dpTable[i][j] << std::endl;
        }

        for (int i = 1; i <= sLength; ++i) {
            for (int j = 1; j <= pLength; ++j) {
                if(p[j-1] == '.' || s[i-1] == p[j-1]) {
                    dpTable[i][j] = dpTable[i-1][j-1];
                }
                else if(p[j-1] == '*') {
                    bool isUsed = (s[i-1] == p[j-2] || p[j-2] == '.') ? dpTable[i-1][j] : false;
                    bool isLastOccurence = dpTable[i][j-2];
                    dpTable[i][j] = isUsed || isLastOccurence;
                }
                //std::cout << "i:" << i << " j:" << j << " Value: " << dpTable[i][j] << std::endl;
            }
        }
        return dpTable[sLength][pLength];
    }
};