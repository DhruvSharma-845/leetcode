#include <vector>
#include <utility>
#include <algorithm>

class Solution {
public:
    int earliestFullBloom(std::vector<int>& plantTime, std::vector<int>& growTime) {
        std::vector<std::pair<int, int>> timesPair;
        timesPair.reserve(plantTime.size());

        for(int i = 0; i < plantTime.size(); ++i) {
            timesPair.push_back(std::make_pair(plantTime[i], growTime[i]));
        }

        std::sort(timesPair.begin(), timesPair.end(), [](const auto& a, const auto& b) {
            if(a.second == b.second) {
                return a.first > b.first;
            }
            else {
                return a.second > b.second;
            }
        });

        int totalTime = 0;
        int timeToStartPlanting = 0;
        for(int i = 0; i < timesPair.size(); ++i) {
            const auto& [pTime, gTime] = timesPair[i];
            totalTime = std::max(totalTime,  timeToStartPlanting + pTime + gTime);
            timeToStartPlanting += pTime; 
        }
        return totalTime;
    }
};