#pragma once

#include <string>
#include <stack>

class Solution {
public:
    bool isValid(std::string s) {
        std::stack<char> st;
        for(const auto& ch: s) {
            if(ch == '(' || ch == '[' || ch == '{') {
                st.push(ch);
            }
            else if(ch == ')') {
                if(st.empty() == true || st.top() != '(') {
                    return false;
                }
                else {
                    st.pop();
                }
            }
            else if(ch == ']') {
                if(st.empty() == true || st.top() != '[') {
                    return false;
                }
                else {
                    st.pop();
                }
            }
            else if(ch == '}') {
                if(st.empty() == true || st.top() != '{') {
                    return false;
                }
                else {
                    st.pop();
                }
            }
        }
        return (st.empty() ? true: false);
    }
};