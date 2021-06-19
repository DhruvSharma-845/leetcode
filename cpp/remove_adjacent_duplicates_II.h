#include <iostream>
#include <string>
#include <stack>
#include <utility>
#include <map>

class Solution {
public:
    std::string removeDuplicates(std::string s, int k) {
        std::stack<std::pair<char, int>> st;
        std::stack<int> lengthSt;

        st.push(std::make_pair(s[0], 0));
        lengthSt.push(1);
        
        std::map<int, int> indices;
        auto initialChar = s[0];
        //int lengthTillNow = 1;
        auto isRemoved = bool{false};
        for (int i = 1; i < s.length(); i++) {
            if(s[i] == initialChar) {
                //std::cout << s[i] << " " << initialChar << std::endl;
                if(!lengthSt.empty()) {
                    (lengthSt.top())++;
                }
                //std::cout << "Length: " << lengthSt.top() << std::endl;
                if(lengthSt.top() == k) {
                    std::pair<char,int> p{st.top()};
                    st.pop();
                    lengthSt.pop();
                    //std::cout << p.second << " " << i << std::endl;
                    indices.insert(std::make_pair(p.second, i));
                    isRemoved = true;
                    initialChar = st.empty() ? '#' : st.top().first;
                }
            }
            else {
                st.push(std::make_pair(s[i], i));
                lengthSt.push(1);
                initialChar = s[i];
            }
        }
        
        if(isRemoved) {
            std::string resString;
            auto it = indices.begin();
            for(int i = 0; i < s.length(); i++) {
                if(it != indices.end() && i >= it->first && i <= it->second) {
                    i = it->second;
                    it++;
                    while(it != indices.end() && i >= it->second) {
                        it++;
                    }
                }
                else {
                    resString.push_back(s[i]);
                }
            }
            return resString;
        }
        return s;
    }
};