#include <vector>
#include <unordered_map>
#include <algorithm>

class Solution {
private:
    auto findLargestTimeOnPath(int node, const std::unordered_map<int, std::vector<int>>& diGraph, std::vector<int>& informTime, int pathTime) -> int {
        int nextPathTime = pathTime + informTime[node];
        if(diGraph.find(node) != diGraph.end()) {
            int maxTime = 0;
            const auto& children = diGraph.at(node);
            for(auto child: children) {
                int childPathTime = findLargestTimeOnPath(child, diGraph, informTime, nextPathTime);
                maxTime = std::max(maxTime, childPathTime);
            }
            return maxTime;
        }
        return nextPathTime;
    }

public:
    int numOfMinutes(int n, int headID, std::vector<int>& manager, std::vector<int>& informTime) {
        std::unordered_map<int, std::vector<int>> diGraph;
        for(int i = 0; i < n; i++) {
            if(manager[i] != -1) {
                diGraph[manager[i]].push_back(i);
            }
        }

        int res = findLargestTimeOnPath(headID, diGraph, informTime, 0);
        return res;
    }
};