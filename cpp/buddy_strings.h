#include <string>
#include <unordered_map>

class Solution {
public:
    bool buddyStrings(const std::string& s, const std::string& goal) {
        
        int len = s.length();
        if(len != goal.length()) {
            return false;
        }

        std::unordered_map<char, int> equalCharIndices;

        int notEqualIndex1 = -1;
        int notEqualIndex2 = -1;
        bool equalSwapPossible = false;
        for(int i = 0; i < len; i++) {
            if(s[i] == goal[i]) {
                if(equalCharIndices.find(s[i]) != equalCharIndices.end()) {
                    equalSwapPossible = true;
                }
                else {
                    equalCharIndices[s[i]] = i;
                }
            }
            else {
                if(notEqualIndex1 == -1) {
                    notEqualIndex1 = i;
                }
                else if(notEqualIndex2 == -1) {
                    notEqualIndex2 = i;
                }
                else {
                    return false;
                }
            }
        }

        if(notEqualIndex1 != -1) {
            if(notEqualIndex2 != -1) {
                if(s[notEqualIndex1] == goal[notEqualIndex2] && s[notEqualIndex2] == goal[notEqualIndex1]) {
                    return true;
                }
                else {
                    return false;
                }
            }
            else {
                return false;
            }
        }
        return equalSwapPossible;
    }
};