#include <string>
#include <vector>
#include <algorithm>

class Solution {
private:
    auto hasOneCharacterDifference(const std::string& bigger, const std::string& smaller) -> bool {
        if(bigger.length() == smaller.length() + 1) {
            bool foundOneDifference = false;
            for (int i = 0, j = 0; i < smaller.length();) {
                if(bigger[j] != smaller[i]) {
                    if(foundOneDifference == false ) {
                        foundOneDifference = true;
                    }
                    else {
                        return false;
                    }
                    j++;
                } else {
                    i++;
                    j++;
                } 
            }
            return true;
        }
        return false;
    }
public:
    int longestStrChain(std::vector<std::string>& words) {
        std::sort(words.begin(), words.end(), [](const std::string& a, const std::string& b) {
            return a.length() < b.length();
        });
        //std::copy(words.begin(), words.end(), std::ostream_iterator<std::string>(std::cout, " "));
        std::vector<int> dpTable(words.size(), 1);
        int maxLength = 1;
        for (int i = 1; i < words.size(); i++) {
            for (int j = i - 1; j >= 0; j--) {
                if(hasOneCharacterDifference(words[i], words[j]) == true) {
                    dpTable[i] = std::max(dpTable[i], dpTable[j] + 1);
                }
            }
            maxLength = std::max(maxLength, dpTable[i]);
        }
        return maxLength;
    }
};