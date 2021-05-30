#include <iostream>
#include <vector>
#include <unordered_map>
#include <limits>

class Solution {
public:
    int findCheapestPrice(int n, std::vector<std::vector<int>>& flights, int src, int dst, int k) {
        std::vector<std::unordered_map<int, int>> graph(n, std::unordered_map<int, int>());
        for(const auto& flight: flights) {
            graph[flight[0]][flight[1]] = flight[2];
        }
        k++;
        std::vector<std::vector<int>> table(k + 1, std::vector<int>(n + 1, std::numeric_limits<int>::max()));
        table[0][src] = 0;
        auto minVal = int{std::numeric_limits<int>::max()};
        for(int i = 1; i <= k; i++) {
            std::cout << i << std::endl;
            for(int ver = 0; ver < n; ver++) {
                
                const auto& adj = graph[ver];
                for(const auto& pr: adj) {
                    if(table[i-1][ver] != std::numeric_limits<int>::max()) {
                        if(table[i][pr.first] > table[i-1][ver] + pr.second) {
                            table[i][pr.first] = table[i-1][ver] + pr.second;
                        }
                    }
                }
                table[i][ver] = std::min(table[i][ver], table[i-1][ver]);
            }
            if(table[i][dst] < minVal) {
                minVal = table[i][dst];
            }
        }
        return (minVal == std::numeric_limits<int>::max()) ? -1 : minVal;
    }
};

