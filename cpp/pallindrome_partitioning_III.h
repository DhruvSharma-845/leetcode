#include <iostream>
#include <string>
#include <vector>
#include <limits>

class Solution {
private:
    void populateTableForChangesToMakePalindrome(const std::string& s, std::vector<std::vector<int>>& dpTable) {
        for(int diagonal = 1; diagonal < s.length(); ++diagonal) {
            for (int i = 0; i < (s.length() - diagonal); i++) {
                int j = i + diagonal;
                dpTable[i][j] = dpTable[i+1][j-1] + (s[i] != s[j] ? 1 : 0);
                //std::cout << i << " " << j << " -> " << dpTable[i][j] << std::endl; 
            }
        }
    }
public:
    int palindromePartition(std::string& s, int k) {
        std::vector<std::vector<int>> changesDpTable(s.length(), std::vector<int>(s.length(), 0));
        populateTableForChangesToMakePalindrome(s, changesDpTable);

        std::vector<std::vector<int>> dpTable(s.length() + 1, std::vector<int>(k + 1, MIN_VAL));
        dpTable[0][0] = 0;

        for(int partition = 1; partition <= k; partition++) {
            for(int i = partition; i <= s.length(); i++) {
                int minVal = std::numeric_limits<int>::max();
                for(int j = i; j > 0; j--) {
                    if(dpTable[j-1][partition-1] != MIN_VAL) {
                        minVal = std::min(changesDpTable[j-1][i-1] + dpTable[j-1][partition-1], minVal);
                    }   
                }
                dpTable[i][partition] = minVal;
            }
        }

        return dpTable[s.length()][k];
    }
private:
    const int MIN_VAL = std::numeric_limits<int>::min();
};