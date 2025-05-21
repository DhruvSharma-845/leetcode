//
// Created by Dhruv Sharma on 12/05/25.
//

#ifndef REORDER_ROUTES_TO_CITY_ZERO_H
#define REORDER_ROUTES_TO_CITY_ZERO_H

#include <vector>
#include <utility>
#include <queue>

class Solution {
public:
    int minReorder(int n, std::vector<std::vector<int>>& connections) {
        std::vector<std::vector<std::pair<int, int>>> graph(n);
        for (const auto& connection: connections) {
            graph[connection[0]].push_back(std::make_pair(connection[1], 1));
            graph[connection[1]].push_back(std::make_pair(connection[0], 0));
        }

        int reorderingEdges = 0;
        // do bfs

        std::vector<bool> visited(n, false);

        std::queue<int> que;
        que.push(0);
        while (!que.empty()) {

            int currentNode = que.front();
            que.pop();
            visited[currentNode] = true;

            // check neighbors
            for (const auto& neighbor: graph[currentNode]) {
                if (!visited[neighbor.first]) {
                    que.push(neighbor.first);
                    if (neighbor.second == 1) {
                        ++reorderingEdges;
                    }
                }
            }
        }
        return reorderingEdges;
    }
};

#endif //REORDER_ROUTES_TO_CITY_ZERO_H
