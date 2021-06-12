/*
abcabcababa a
ab ab ab ab ab ab cb cc
bac bac bac ba bbb

ba ba ba ba bc bc bc
*/

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

class Solution {
public:
    std::string reorganizeString(std::string& s) {
        std::vector<int> count(26, 0);
        for(auto ch: s) {
           count[static_cast<int>(ch) - 97]++; 
        }

        int index = -1;
        int maxVal = 0;
        for (size_t i = 0; i < 26; i++) {
            if(count[i] > maxVal) {
                maxVal = count[i];
                index = i; 
            }
        }
        char charOfMaxFreq = static_cast<char>(index + 97);
        if(maxVal > (s.length() + 1)/ 2) {
            return std::string("");
        }
        
        std::string reorderedString(s);
        int i = 0;
        for (; maxVal > 0; i += 2) {
            reorderedString[i] = charOfMaxFreq;
            count[index]--;
            maxVal--;
        }

        for(int c = 0; c < 26; c++) {
            while(count[c] > 0) {
                i = (i >= s.length() ? 1 : i);
                reorderedString[i] = static_cast<char>(c + 97);
                i += 2;
                count[c]--;
            }
        }
        return reorderedString;
    }
};