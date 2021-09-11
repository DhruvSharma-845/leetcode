#include <vector>
#include <map>
#include <iostream>

class Solution {
public:
    bool isPossibleDivide(std::vector<int>& nums, int k) {
        std::map<int, int> freqCount;
        for (auto &num : nums) {
            freqCount[num]++;
        }
        
        while(!freqCount.empty()) {
            int i = 0;
            int prev = -1;
            for(auto& pr: freqCount) {
                if(prev == -1) {
                    prev = pr.first;
                }
                else {
                    if(pr.first != prev + 1) {
                        return false; 
                    }
                    prev = pr.first;
                }
                freqCount[pr.first]--;
                if(freqCount[pr.first] == 0) {
                    freqCount.erase(pr.first);
                }
                i++;
                if(i == k) {
                    break;
                }
            }
            if(i != k) {
                return false;
            }
        }
        return true;
    }
};