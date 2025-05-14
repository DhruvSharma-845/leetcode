//
// Created by Dhruv Sharma on 14/05/25.
//

#ifndef THRONE_INHERITANCE_H
#define THRONE_INHERITANCE_H

#include <string>
#include <vector>
#include <unordered_map>
#include <utility>
#include <stack>

class ThroneInheritance {
private:
    std::unordered_map<std::string, std::pair<bool, std::vector<std::string>>> tree;
    std::string kingName{""};
public:
    ThroneInheritance(std::string kingName): kingName(kingName) {
        if (tree.find(kingName) == tree.end()) {
            tree.insert(std::make_pair(kingName, std::make_pair(true, std::vector<std::string>())));
        }
    }

    void birth(std::string parentName, std::string childName) {
        this->tree[parentName].second.push_back(childName);
        this->tree[childName].first = true;
    }

    void death(std::string name) {
        this->tree[name].first = false;
    }

    void getOrderRecursive(std::string node, std::vector<std::string>& order) {

        std::stack<std::string> st;
        st.push(node);

        while (!st.empty()) {
            const auto& curr = st.top();
            st.pop();

            const auto& val = this->tree[curr];
            if (val.first == true) {
                order.push_back(curr);
            }

            for (auto it = val.second.rbegin(); it != val.second.rend(); it++) {
                st.push(*it);
            }
        }
    }

    std::vector<std::string> getInheritanceOrder() {
        std::vector<std::string> order;
        this->getOrderRecursive(this->kingName, order);
        return order;
    }
};

#endif //THRONE_INHERITANCE_H
