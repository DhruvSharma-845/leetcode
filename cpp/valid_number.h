#include <iostream>
#include <string>
#include <vector>
#include <map>

class Solution {
private:
    std::map<char, int> charToColumnIndex{
        {'+', 0},
        {'-', 0},
        {'e', 2},
        {'E', 2},
        {'.', 3},
        {'0', 1},
        {'1', 1},
        {'2', 1},
        {'3', 1},
        {'4', 1},
        {'5', 1},
        {'6', 1},
        {'7', 1},
        {'8', 1},
        {'9', 1}
    };
    // sign, number, e/E, .
    std::vector<std::vector<int>> stateMachine{
        { 1, 2, -1, 3}, // state 0
        {-1, 2, -1 , 8}, // state 1 
        {-1, 2, 5, 7}, // state 2
        {-1, 4, -1, -1}, // state 3 (after dot)
        {-1, 4, 5, -1}, // state 4 (number after dot)
        {9, 6, -1, -1}, // state 5 (after e/E)
        {-1, 6, -1, -1}, // state 6 (number after e/E)
        {-1, 4, 5, -1}, // state 7 (dot following number)
        {-1, 7, -1, -1}, // state 8
        {-1, 6, -1, -1} // state 9 (number followed by e/E +/-)
    };
public:
    bool isNumber(const std::string& s) {
        auto state = 0;
        for(const auto& ch: s) {
            if(charToColumnIndex.find(ch) == charToColumnIndex.end()) {
                return false;
            }
            auto column = charToColumnIndex.at(ch);
            auto nextState = stateMachine[state][column];
            if(nextState == -1) {
                return false;
            }
            state = nextState;
        }
        return (state == 2 || state == 4 || state == 6 || state == 7);
    }
};



/*

*/
