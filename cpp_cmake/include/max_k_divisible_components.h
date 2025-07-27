//
// Created by Dhruv Sharma on 27/07/25.
//

#ifndef MAX_K_DIVISIBLE_COMPONENTS_H
#define MAX_K_DIVISIBLE_COMPONENTS_H

#include <vector>
#include <unordered_map>

class Solution {
private:
    auto dfsUtil(int node, int parent, const std::unordered_map<int, std::vector<int>>& graph, int& componentCount, const std::vector<int>& values, int k) -> int {
        int sum = 0;
        if (graph.find(node) != graph.end()) {
            for (const auto& neighbor: graph.at(node)) {
                if (neighbor != parent) {
                    sum += dfsUtil(neighbor, node, graph, componentCount, values, k);
                    sum %= k;
                }
            }
        }
        sum += values[node];
        sum %= k;

        if (sum == 0) {
            ++componentCount;
        }
        return sum;
    }
public:
    int maxKDivisibleComponents(int n, std::vector<std::vector<int>>& edges, std::vector<int>& values, int k) {
        std::unordered_map<int, std::vector<int>> graph;

        for (const auto& edge: edges) {
            graph[edge[0]].push_back(edge[1]);
            graph[edge[1]].push_back(edge[0]);
        }

        int componentCount = 0;
        dfsUtil(0, -1, graph, componentCount, values, k);
        return componentCount;
    }
};

#endif //MAX_K_DIVISIBLE_COMPONENTS_H
