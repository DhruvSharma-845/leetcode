#include <string>
#include <vector>

class Solution {
public:
    std::string restoreString(std::string s, std::vector<int>& indices) {
        std::string shuffledString = s;
        
        int currentIndex = 0;
        for(int index: indices) {
            shuffledString[index] = s.at(currentIndex);
            ++currentIndex;
        }
        
        return shuffledString;
    }
};