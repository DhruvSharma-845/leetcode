//
// Created by Dhruv Sharma on 15/06/25.
//

#ifndef MAXIMUM_TARGET_NODES_II_H
#define MAXIMUM_TARGET_NODES_II_H

#include <vector>
#include <unordered_map>
#include <queue>

using graph_edges = std::vector<std::vector<int>>;
using graph_type = std::unordered_map<int, std::vector<int>>;

class Solution {
private:
    void fillDistances(graph_type& graph, int node, std::pair<int, int>& evenOddDistances) {
        // do bfs
        std::vector<bool> visited(graph.size(), false);

        std::queue<int> que1;
        std::queue<int> que2;
        que1.push(node);
        evenOddDistances.second++;

        while (!que1.empty() || !que2.empty()) {
            while (!que1.empty()) {
                int current = que1.front();
                que1.pop();
                visited[current] = true;
                for (const auto& neighbor: graph[current]) {
                    if (visited[neighbor] == false) {
                        que2.push(neighbor);
                        evenOddDistances.first++;
                    }
                }
            }
            while (!que2.empty()) {
                int current = que2.front();
                que2.pop();
                visited[current] = true;
                for (const auto& neighbor: graph[current]) {
                    if (visited[neighbor] == false) {
                        que1.push(neighbor);
                        evenOddDistances.second++;
                    }
                }
            }
        }
    }
public:
    std::vector<int> maxTargetNodes(graph_edges& edges1, graph_edges& edges2) {

        std::vector<int> result;

        graph_type graph2;
        for (const auto& edge: edges2) {
            graph2[edge[0]].push_back(edge[1]);
            graph2[edge[1]].push_back(edge[0]);
        }

        std::pair<int, int> evenOddDistancesGraph2Node1(std::make_pair(0, 0));

        fillDistances(graph2, 0, evenOddDistancesGraph2Node1);

        int maxOddGraph2 = std::max(evenOddDistancesGraph2Node1.first, evenOddDistancesGraph2Node1.second);
        int maxEvenGraph2 = maxOddGraph2;

        graph_type graph1;
        for (const auto& edge: edges1) {
            graph1[edge[0]].push_back(edge[1]);
            graph1[edge[1]].push_back(edge[0]);
        }
        result.resize(graph1.size());

        std::pair<int, int> evenOddDistancesGraph1Node1(std::make_pair(0, 0));
        std::pair<int, int> evenOddDistancesGraph1Node2(std::make_pair(0, 0));

        fillDistances(graph1, 0, evenOddDistancesGraph1Node1);

        evenOddDistancesGraph1Node2.first = evenOddDistancesGraph1Node1.second;
        evenOddDistancesGraph1Node2.second = evenOddDistancesGraph1Node1.first;

        // do bfs
        std::vector<bool> visited(graph1.size(), false);

        std::queue<int> que1;
        std::queue<int> que2;
        que1.push(0);

        while (!que1.empty() || !que2.empty()) {
            while (!que1.empty()) {
                int current = que1.front();
                que1.pop();
                visited[current] = true;
                int selfCount = evenOddDistancesGraph1Node1.second + maxOddGraph2;
                int oneDistanceNeighbor = evenOddDistancesGraph1Node1.second + maxEvenGraph2;

                result[current] = std::max(selfCount, oneDistanceNeighbor);

                for (const auto& neighbor: graph1[current]) {
                    if (visited[neighbor] == false) {
                        que2.push(neighbor);
                    }
                }
            }
            while (!que2.empty()) {
                int current = que2.front();
                que2.pop();
                visited[current] = true;
                int selfCount = evenOddDistancesGraph1Node2.second + maxOddGraph2;
                int oneDistanceNeighbor = evenOddDistancesGraph1Node2.second + maxEvenGraph2;

                result[current] = std::max(selfCount, oneDistanceNeighbor);
                for (const auto& neighbor: graph1[current]) {
                    if (visited[neighbor] == false) {
                        que1.push(neighbor);
                    }
                }
            }
        }

        return result;
    }
};

#endif //MAXIMUM_TARGET_NODES_II_H
