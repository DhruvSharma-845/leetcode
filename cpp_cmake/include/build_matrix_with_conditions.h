#include <vector>
#include <unordered_map>
#include <queue>

class Solution {
private:

    auto findTopologicalOrder(int k, std::vector<std::vector<int>>& links) -> std::vector<int> {
        std::unordered_map<int, std::vector<int>> graph;
        for(const auto& link: links) {
            graph[link[0]].push_back(link[1]);
        }

        std::vector<int> inDegree(k + 1, 0);
        std::vector<int> topOrder;
        std::queue<int> q;
        for (int i = 1; i <= k; ++i) {
            for (const auto& j : graph[i]) {
                ++inDegree[j];
            }
        }
        for (int i = 1; i <= k; ++i) {
            if (inDegree[i] == 0) q.push(i);
        }
        while (!q.empty()) {
            int node = q.front(); 
            q.pop();
            topOrder.push_back(node);
            for (const auto& adj : graph[node]) {
                if (--inDegree[adj] == 0) q.push(adj);
            }
        }
        return topOrder.size() == k ? topOrder : std::vector<int>();
    }
public:
    std::vector<std::vector<int>> buildMatrix(int k, std::vector<std::vector<int>>& rowConditions, std::vector<std::vector<int>>& colConditions) {
        auto rowTopOrder = this->findTopologicalOrder(k, rowConditions);
        auto colTopOrder = this->findTopologicalOrder(k, colConditions);
        
        std::vector<std::vector<int>> resMatrix;
        if(rowTopOrder.empty() || colTopOrder.empty()) {
            return resMatrix;
        }
        for(const auto& rowElement: rowTopOrder) {
            auto it = std::find(colTopOrder.begin(), colTopOrder.end(), rowElement);
            if(it != colTopOrder.end()) {
                int colIndex = std::distance(colTopOrder.begin(), it);
                std::vector<int> rowVector(k, 0);
                rowVector[colIndex] = rowElement;;
                resMatrix.push_back(rowVector);
            }
        }
        return resMatrix;
    }
};