//
// Created by Dhruv Sharma on 25/06/25.
//

#ifndef VISIBLE_PEOPLE_QUEUE_H
#define VISIBLE_PEOPLE_QUEUE_H

#include <vector>
#include <stack>

class Solution {
public:
    std::vector<int> canSeePersonsCount(std::vector<int>& heights) {
        std::vector<int> result(heights.size(), 0);

        std::stack<int> st;
        st.push(heights.size() - 1);

        for (int i = heights.size() - 2; i >= 0; --i) {
            if (heights[i] <= heights[i + 1]) {
                result[i] = 1;
                st.push(i);
            }
            else {
                int count = 0;
                while (!st.empty() && heights[st.top()] < heights[i]) {
                    ++count;
                    st.pop();
                }
                if (!st.empty()) {
                    ++count;
                }
                result[i] = count;
                st.push(i);
            }
        }
        return result;
    }
};

#endif //VISIBLE_PEOPLE_QUEUE_H
