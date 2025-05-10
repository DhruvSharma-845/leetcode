//
// Created by Dhruv Sharma on 10/05/25.
//

#ifndef FIND_CHAMPION_2_H
#define FIND_CHAMPION_2_H

#include <vector>

class Solution {
public:
    int findChampion(int n, std::vector<std::vector<int>>& edges) {
        std::vector<int> indegree(n, 0);

        for (const auto& edge: edges) {
            indegree[edge[1]]++;
        }

        int index = -1;
        for (int i = 0; i < n; i++) {
            if (indegree[i] == 0) {
                if (index == -1) {
                    index = i;
                }
                else {
                    index = -1;
                    break;
                }
            }
        }
        return index;
    }
};

#endif //FIND_CHAMPION_2_H
