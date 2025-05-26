//
// Created by Dhruv Sharma on 25/05/25.
//

#ifndef TWO_BEST_NON_OVERLAPPING_EVENTS_H
#define TWO_BEST_NON_OVERLAPPING_EVENTS_H

#include <vector>
#include <algorithm>
#include <utility>

class Solution {
public:
    int maxTwoEvents(std::vector<std::vector<int>>& events) {

        std::vector<std::pair<int, int>> eventStartTimes(events.size());
        std::vector<std::pair<int, int>> eventEndTimes(events.size());
        for (int i = 0; i < events.size(); ++i) {
            eventStartTimes[i] = std::make_pair(events[i][0], i);
            eventEndTimes[i] = std::make_pair(events[i][1], i);
        }

        std::sort(eventStartTimes.begin(), eventStartTimes.end(), [](const auto& a, const auto& b) {
            if (a.first == b.first) {
                return a.second < b.second;
            }
            return a.first < b.first;
        });

        std::sort(eventEndTimes.begin(), eventEndTimes.end(), [](const auto& a, const auto& b) {
            if (a.first == b.first) {
                return a.second < b.second;
            }
            return a.first < b.first;
        });

        int startIndex = 0;
        int endIndex = 0;

        int maxElementTillNow = 0;
        int totalMax = 0;
        while (startIndex < eventStartTimes.size() && endIndex < eventEndTimes.size()) {
            if (eventStartTimes[startIndex].first <= eventEndTimes[endIndex].first) {
                int value = events[eventStartTimes[startIndex].second][2];
                totalMax = std::max(totalMax, maxElementTillNow + value);
                ++startIndex;
            }
            else {
                int value = events[eventEndTimes[endIndex].second][2];
                maxElementTillNow = std::max(maxElementTillNow, value);
                totalMax = std::max(totalMax, value);
                ++endIndex;
            }
        }

        while (endIndex < eventEndTimes.size()) {
            int value = events[eventEndTimes[endIndex].second][2];
            totalMax = std::max(totalMax, value);
            ++endIndex;
        }


        return totalMax;
    }
};

#endif //TWO_BEST_NON_OVERLAPPING_EVENTS_H
