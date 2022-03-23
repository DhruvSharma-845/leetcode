#include <string>

class Solution {
public:
    int maxPower(const std::string& s) {
        int maxCount = 0;

        int currentCount = 1;
        int currentChar = s[0];
        for(int i = 1; i < s.length(); ++i) {
            if(s[i] == currentChar) {
                ++currentCount;
            }
            else {
                if(currentCount > maxCount) {
                    maxCount = currentCount;
                }
                currentChar = s[i];
                currentCount = 1;
            }
        }
        return std::max(maxCount, currentCount);
    }
};