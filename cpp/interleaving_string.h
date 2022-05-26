#include <string>
#include <vector>

class Solution {
public:
    bool isInterleave(std::string s1, std::string s2, std::string s3) {
        int s1Length = s1.size();
        int s2Length = s2.size();
        if((s1Length + s2Length) != static_cast<int>(s3.size())) {
            return false;
        }
        std::vector<std::vector<bool>> dpTable(s1Length + 1, std::vector<bool>(s2Length + 1, false));
        dpTable[0][0] = true;
        for(int i = 1; i <= s1Length; ++i) {
            dpTable[i][0] = (s1[i-1] == s3[i-1]) && dpTable[i-1][0];
        }

        for (int j = 1; j <= s2Length; ++j) {
            dpTable[0][j] = (s2[j-1] == s3[j-1]) && dpTable[0][j-1];
        }

        for(int i = 1; i <= s1Length; ++i) {
            for(int j = 1; j <= s2Length; ++j) {
                bool currentValue = false;
                if(s1[i-1] == s3[i+j-1]) {
                    currentValue = dpTable[i-1][j];
                } 
                if(currentValue == false && s2[j-1] == s3[i+j-1]) {
                    currentValue = dpTable[i][j-1];
                }
                dpTable[i][j] = currentValue;
                //std::cout << "i:" << i << " j:" << j << " -> " << dpTable[i][j] << std::endl;
            }
        }

        return dpTable[s1Length][s2Length];
    }
};