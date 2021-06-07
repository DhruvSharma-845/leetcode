#include <iostream>
#include <vector>
#include <string>
#include <queue>
#include <set>
#include <unordered_set>

class Solution {
public:
    int openLock(std::vector<std::string>& deadends, std::string& target) {

        std::set<std::string> deadEnds(deadends.begin(), deadends.end());
        if(deadEnds.find("0000") != deadEnds.end() || deadEnds.find(target) != deadEnds.end()) {
            return -1;
        }
        std::unordered_set<std::string> visited;

        std::string s("0000");
        std::queue<std::string> que;
        que.push(s);
        visited.insert(s);

        auto level = 0;
        while(!que.empty()) {
            int sz = que.size();
            while(sz > 0) {
                std::string str = que.front();
                que.pop();
                std::cout << level << " " << str << std::endl;
                if(str.compare(target) == 0) {
                    return level;
                }
                for (size_t i = 0; i < 4; i++) {
                    int currentNum = static_cast<int>(str[i]) - 48;

                    std::string newString1(str);
                    newString1[i] = static_cast<char>(((currentNum + 1) % 10) + 48);
                    if(deadEnds.find(newString1) == deadEnds.end() && visited.find(newString1) == visited.end()) {
                        que.push(newString1);
                        visited.insert(newString1);
                    }

                    std::string newString2(str);
                    newString2[i] = static_cast<char>(((currentNum - 1 + 10) % 10) + 48);
                    if(deadEnds.find(newString2) == deadEnds.end() && visited.find(newString2) == visited.end()) {
                        que.push(newString2);
                        visited.insert(newString2);
                    }
                }
                sz--;
            }
            level++;
        }
        return -1;
    }
};