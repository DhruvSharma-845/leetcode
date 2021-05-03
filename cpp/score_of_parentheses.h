#include <string>
#include <stack>
#include <cmath>

class Solution {
public:
    int scoreOfParentheses(const std::string& S) {
        int finalVal = 0;
        int depth = 0;
        for(auto i = 0; i < S.length(); ++i) {
            if(S[i] == '(') {
                ++depth;
            }
            else if(S[i] == ')') {
                if(S[i-1] == '(') {
                    finalVal += pow(2, depth-1);
                }
                --depth;
            }
        }
        return finalVal;
    }
};