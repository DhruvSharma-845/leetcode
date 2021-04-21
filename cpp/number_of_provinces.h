#include <iostream>
#include <vector>
#include <queue>

class Solution {
public:
    int findCircleNum(std::vector<std::vector<int>>& isConnected) {
        int sum = 0;
        std::vector<bool> isVisited(isConnected.size(), false);
        for (int i = 0; i < isConnected.size(); ++i) {
            if(isVisited[i] == false) {
                ++sum;
                findCircleNumUtil(i, isConnected, isVisited);
            }
        }
        return sum;
    }

    void findCircleNumUtil(int city, const std::vector<std::vector<int>>& isConnected, std::vector<bool>& isVisited) {
        isVisited[city] = true;
        std::queue<int> que;
        que.push(city);
        int cols = isConnected[0].size();
        while(!que.empty()) {
            int ver = que.front();
            que.pop();

            for(int i = 0; i < cols; ++i) {
                if(i != city && isConnected[ver][i] == 1 && isVisited[i] == false) {
                    isVisited[i] = true;
                    que.push(i);
                }
            }
        }
    }
};