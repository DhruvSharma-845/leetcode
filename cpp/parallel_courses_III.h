#include <vector>
#include <unordered_map>
#include <stack>
#include <iostream>
#include <limits>
#include <algorithm>

class Solution {
private:
    void findTopologicalOrder(int N, const std::unordered_map<int, std::vector<int>>& graph, int vertex, std::vector<bool>& visited, std::stack<int>& st) {
        
        visited[vertex] = true;
        if(graph.find(vertex) != graph.end()) {
            for(const auto& neighbor: graph.at(vertex)) {
                if(visited[neighbor] == false) {
                    findTopologicalOrder(N, graph, neighbor, visited, st);
                }
            }
        }
        st.push(vertex);
    }
public:
    
    int minimumTime(int n, std::vector<std::vector<int>>& relations, std::vector<int>& time) {
        // creating graph
        std::unordered_map<int, std::vector<int>> graph;
        for(const auto& edge: relations) {
            graph[edge[0] - 1].push_back(edge[1] - 1);
        }

        std::stack<int> st;
        std::vector<bool> visited(n, false);
        std::vector<int> maxTimes(n, 0);
        for(int i = 0; i < n; ++i) {
            if(visited[i] == false) {
                findTopologicalOrder(n, graph, i, visited, st);
            }
            maxTimes[i] = time[i];
        }
        
        while(!st.empty()) {
            std::cout << st.top() << std::endl;
            int u = st.top();
            st.pop();

            for(const auto& neighbor: graph[u]) {
                if(maxTimes[neighbor] < (time[neighbor] + maxTimes[u])) {
                    maxTimes[neighbor] = time[neighbor] + maxTimes[u];
                }
            }
        }

        return *max_element(maxTimes.begin(), maxTimes.end());
    }
};