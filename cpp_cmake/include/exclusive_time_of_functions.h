//
// Created by Dhruv Sharma on 17/05/25.
//

#ifndef EXCLUSIVE_TIME_OF_FUNCTIONS_H
#define EXCLUSIVE_TIME_OF_FUNCTIONS_H

#include <vector>
#include <string>
#include <stack>
#include <sstream>

class Solution {
public:
    std::vector<int> exclusiveTime(int n, std::vector<std::string>& logs) {
        std::stack<int> st;

        int lastTimeStamp = -1;
        int lastStatus = -1;

        std::vector<int> result(n, 0);

        for (const auto& log: logs) {

            std::size_t foundIndex = log.find(":");
            int funcId = std::stoi(log.substr(0, foundIndex));
            int currentStatus = log[foundIndex + 1] == 's' ? 0 : 1;

            foundIndex = log.find(":", foundIndex + 1);
            int currentTimestamp = std::stoi(log.substr(foundIndex + 1 ));

            if (currentStatus == 0) {
                if (lastStatus == 0) {
                    result[st.top()] += (currentTimestamp - lastTimeStamp);
                }
                else if (lastStatus == 1) {
                    if (!st.empty()) {
                        result[st.top()] += (currentTimestamp - lastTimeStamp - 1);
                    }
                }
                st.push(funcId);
            }
            else if (currentStatus == 1) {
                if (lastStatus == 0) {
                    result[st.top()] += (currentTimestamp - lastTimeStamp + 1);
                }
                else if (lastStatus == 1) {
                    result[st.top()] += (currentTimestamp - lastTimeStamp);
                }
                st.pop();
            }
            lastStatus = currentStatus;
            lastTimeStamp = currentTimestamp;
        }
        return result;
    }
};

#endif //EXCLUSIVE_TIME_OF_FUNCTIONS_H
