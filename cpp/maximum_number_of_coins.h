#include <vector>
#include <algorithm>
#include <functional>

class Solution {
public:
    int maxCoins(std::vector<int>& piles) {
        std::sort(piles.begin(), piles.end(), std::greater<int>()); 

        int sum = 0;
        for(int i = 0; i < piles.size() / 3; ++i) {
            sum += piles[i * 2 + 1];
        }   
        return sum;    
    }
};