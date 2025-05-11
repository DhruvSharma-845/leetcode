//
// Created by Dhruv Sharma on 10/05/25.
//

#ifndef SEARCH_SUGGESTION_SYSTEM_H
#define SEARCH_SUGGESTION_SYSTEM_H

#include <vector>
#include <string>
#include <algorithm>

class Solution {
private:

public:
    std::vector<std::vector<std::string>> suggestedProducts(std::vector<std::string>& products, std::string searchWord) {

        std::sort(products.begin(), products.end());

        std::vector<std::vector<std::string>> result;
        result.reserve(searchWord.size());

        int startIndex = 0;
        for (int i = 1; i <= searchWord.size(); ++i) {
            std::vector<std::string> currentResult;
            auto subWord = searchWord.substr(0, i);
            while (startIndex < products.size()) {
                if (subWord == products[startIndex].substr(0, i)) {
                    for (int j = 0; j < 3; ++j) {
                        if (startIndex + j < products.size() && products[startIndex + j].substr(0, i) == subWord) {
                            currentResult.push_back(products[startIndex + j]);
                        }
                    }
                    break;
                }
                ++startIndex;
            }
            result.push_back(currentResult);
        }

        return result;
    }
};

#endif //SEARCH_SUGGESTION_SYSTEM_H
