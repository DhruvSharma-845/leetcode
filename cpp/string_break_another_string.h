#include <iostream>
#include <string>
#include <algorithm>

class Solution {
public:
    bool checkIfCanBreak(std::string s1, std::string s2) {
        std::sort(s1.begin(), s1.end());
        std::sort(s2.begin(), s2.end());

        auto isBreakable1 = bool{true};
        auto isBreakable2 = bool{true};
        for(auto i = 0; i < s1.length(); i++) {
            if(s1[i] > s2[i]) {
                isBreakable1 = false;
            }
            if(s1[i] < s2[i]) {
                isBreakable2 = false;
            }
        } 
        return (isBreakable1 || isBreakable2);
    }
};