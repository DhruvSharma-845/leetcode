#pragma once

#include <vector>
#include <algorithm>
#include <limits>

class Solution {
public:
    int minHeightShelves(std::vector<std::vector<int>>& books, int shelfWidth) {

        std::vector<int> cumulativeWidth(books.size(), 0);

        std::vector<std::vector<int>> dpMaxHeight(books.size(), std::vector<int>(books.size(), 0));

        for(int i = 0; i < books.size(); ++i) {
            cumulativeWidth[i] += (i > 0 ? cumulativeWidth[i-1]: 0) + books[i][0];
            for(int j = i; j < books.size(); ++j) {
                dpMaxHeight[i][j] = std::max(books[j][1], (j > 0 ? dpMaxHeight[i][j-1]: 0));
            }
        }

        std::vector<std::vector<int>> dpTable(books.size() + 1, std::vector<int>(books.size() + 1, std::numeric_limits<int>::max()));

        dpTable[0][0] = 0;

        for(int floor = 1; floor <= books.size(); ++floor) {
            for(int bookEnd = 1; bookEnd <= books.size(); ++bookEnd) {
                for(int bookStart = bookEnd; bookStart > 0; --bookStart) {
                    int currentWidth = cumulativeWidth[bookEnd - 1] - (bookStart > 1 ? cumulativeWidth[bookStart - 1 - 1]: 0);
                    if(currentWidth > shelfWidth) {
                        break;
                    }
                    int maxHeight = dpMaxHeight[bookStart - 1][bookEnd - 1];
                    int result2 = (dpTable[bookStart - 1][floor - 1] == std::numeric_limits<int>::max()) ? std::numeric_limits<int>::max() : (dpTable[bookStart - 1][floor - 1] + maxHeight);
                    dpTable[bookEnd][floor] = std::min(dpTable[bookEnd][floor], result2);
                }
            }
        }

        int minHeightBookCase = std::numeric_limits<int>::max();
        for(int i = 0; i <= books.size(); ++i) {
            minHeightBookCase = std::min(minHeightBookCase, dpTable[books.size()][i]);
        }
        return minHeightBookCase;
    }
};