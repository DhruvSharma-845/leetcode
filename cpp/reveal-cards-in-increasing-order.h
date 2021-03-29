#include <vector>
#include <algorithm>
#include <functional>
#include <list>
#include <cmath>
#include <iostream>

class Solution {
public:
    std::vector<int> deckRevealedIncreasing(std::vector<int>& deck) {
        // sort the original deck
        std::sort(deck.begin(), deck.end(), std::greater<int>());
        int indexIntoSorted = 0; 

        std::list<int> finalCardsList;
        finalCardsList.push_back(deck[indexIntoSorted++]);
        while(indexIntoSorted < deck.size()) {
            int bk = finalCardsList.back();
            finalCardsList.pop_back();
            finalCardsList.push_front(bk);
            finalCardsList.push_front(deck[indexIntoSorted++]);
        }
        
        return std::vector<int>(finalCardsList.begin(), finalCardsList.end());
    }
};