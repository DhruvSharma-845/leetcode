#include <iostream>
#include <vector>
#include <algorithm>

using lli = long long int;
constexpr int LIMIT = 1000000007; 

class Solution {
public:
    int maxArea(int h, int w, std::vector<int>& horizontalCuts, std::vector<int>& verticalCuts) {
        std::sort(horizontalCuts.begin(), horizontalCuts.end());
        std::sort(verticalCuts.begin(), verticalCuts.end());
        std::vector<int> horizontalDiffs;
        auto prevRow = int{0};
        for(auto row: horizontalCuts) {
            horizontalDiffs.push_back(row - prevRow);
            prevRow = row;
        }
        horizontalDiffs.push_back(h - prevRow);

        std::vector<int> verticalDiffs;
        auto prevCol = int{0};
        for(auto col: verticalCuts) {
            verticalDiffs.push_back(col - prevCol);
            prevCol = col;
        }
        verticalDiffs.push_back(w - prevCol);

        std::sort(horizontalDiffs.begin(), horizontalDiffs.end(), std::greater<int>());
        std::sort(verticalDiffs.begin(), verticalDiffs.end(), std::greater<int>());
        auto maxHorz = static_cast<lli>(horizontalDiffs[0]);
        auto maxVert = static_cast<lli>(verticalDiffs[0]);
        return (maxHorz * maxVert) % LIMIT;
    }
};