#include <vector>
#include <algorithm>

class Solution {
public:
    int removeCoveredIntervals(std::vector<std::vector<int>>& intervals) {
        int finalCount = intervals.size();
        for(int i = 0; i < intervals.size(); ++i) {
            for(int j = 0; j < intervals.size(); ++j) {
                if(i != j && isCovered(intervals[i], intervals[j]) == true) {
                    --finalCount;
                    break;
                }
            }
        }
        return finalCount;
    }

    bool isCovered(const std::vector<int>& candidate, const std::vector<int>& parent) {
        if(candidate[0] >= parent[0] && candidate[1] <= parent[1]) {
            return true;
        }
        return false;
    }
};