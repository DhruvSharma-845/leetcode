#include <iostream>
#include <vector>
#include <unordered_set>
#include <unordered_map>
#include <queue>
#include <utility>

class Solution {
public:
    std::vector<int> avoidFlood(std::vector<int>& rains) {
        std::unordered_map<int, std::vector<int>> rainMap;
        std::unordered_map<int, int> indexMap;
        std::unordered_set<int> fullLakes;
        int i, j;
        for(i = 0; i < rains.size(); i++){
            if(rainMap.find(rains[i]) == rainMap.end()){
                std::vector<int> vec;
                rainMap[rains[i]] = vec;
                indexMap[rains[i]] = 0;
            }
            rainMap[rains[i]].push_back(i);
        }
        
        std::priority_queue<std::pair<int, int>, std::vector<std::pair<int, int>>, std::greater<std::pair<int, int>>> pq;
        std::vector<int> ans;
        
        for(i = 0; i < rains.size(); i++){
            if(rains[i] == 0){
                if(pq.empty()){
                    ans.push_back(1);
                }
                else{
                    std::pair<int, int> p = pq.top();
                    pq.pop();
                    fullLakes.erase(p.second);
                    ans.push_back(p.second);
                }
            }
            else{
                if(fullLakes.find(rains[i]) != fullLakes.end()){
                    return std::vector<int> {};
                }
                else{
                    fullLakes.insert(rains[i]);
                    ans.push_back(-1);
                    
                    j = indexMap[rains[i]];
                    if(j + 1 < rainMap[rains[i]].size()){
                        j++;
                        indexMap[rains[i]] = j;
                        pq.push(std::make_pair(rainMap[rains[i]][j], rains[i]));
                    }
                }
            }
        }
        return ans;
    }
};