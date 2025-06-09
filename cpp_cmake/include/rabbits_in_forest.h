//
// Created by Dhruv Sharma on 09/06/25.
//

#ifndef RABBITS_IN_FOREST_H
#define RABBITS_IN_FOREST_H

#include <vector>
#include <unordered_map>

class Solution {
public:
    int numRabbits(std::vector<int>& answers) {
        int totalRabbits = 0;
        std::unordered_map<int, int> colorCounts;
        for (auto i{0}; i < answers.size(); ++i) {
            if (colorCounts.find(answers[i]) == colorCounts.end()) {
                colorCounts[answers[i]] = answers[i];
                totalRabbits += (answers[i] + 1);
            }
            else {
                if (colorCounts[answers[i]] == 0) {
                    colorCounts[answers[i]] = answers[i];
                    totalRabbits += (answers[i] + 1);
                }
                else {
                    colorCounts[answers[i]]--;
                }
            }
        }
        return totalRabbits;
    }
};

#endif //RABBITS_IN_FOREST_H
