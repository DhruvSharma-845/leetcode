#include <iostream>
#include <set>
#include <vector>
#include <algorithm>

class SummaryRanges {
private:
    std::set<int> nums;
public:
    SummaryRanges() {
        
    }
    
    void addNum(int val) {
        nums.insert(val);
    }
    
    std::vector<std::vector<int>> getIntervals() {
        std::vector<std::vector<int>> res;
        auto initialVal = int{-1};
        auto currentEnd = int{-1};
        for (const auto& num : nums) {
            if(initialVal == -1) {
                initialVal = num;
                currentEnd = num;
            }
            else {
                if(num <= currentEnd + 1) {
                    currentEnd = std::max(num, currentEnd);
                }
                else if(num > currentEnd + 1) {
                    std::vector<int> v{initialVal, currentEnd};
                    res.push_back(v); 
                    initialVal = num;
                    currentEnd = num;       
                }
            }
        }
        std::vector<int> v{initialVal, currentEnd};
        res.push_back(v); 
        return res;
    }
};