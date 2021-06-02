#include <iostream>
#include <string>

class Solution {
public:
    std::string pushDominoes(std::string& dominoes) {
        auto left = int{0};
        std::string res{dominoes};
        char prevChar = 'L';
        for (size_t i = 0; i < dominoes.length(); i++) {
            if(dominoes[i] == 'L') {
                if(prevChar == 'L') {
                    while(left != i) {
                        res[left++] = 'L';
                    }
                }
                else if(prevChar == 'R') {
                    auto index = 1;
                    while((left + index) < (i - index)) {
                        res[left + index] = 'R';
                        res[i - index] = 'L';
                        index++;
                    }
                    prevChar = 'L';
                    left = i;
                }
            }
            else if(dominoes[i] == 'R') {
                if(prevChar == 'L') {
                    prevChar = 'R';
                    left = i;
                }
                else if(prevChar == 'R') {
                    while(left != i) {
                        res[left++] = 'R';
                    }
                }
            }
        }
        if(prevChar == 'R') {
            while(left < dominoes.length()) {
                res[left++] = 'R';
            }
        }

        return res;
    }
};