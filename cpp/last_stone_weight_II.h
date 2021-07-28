#include <iostream>
#include <vector>
#include <numeric>

class Solution {
public:
    int lastStoneWeightII(std::vector<int>& stones) {
        if(stones.size() == 1) {
            return stones[0];
        }
        int sum = std::accumulate(stones.begin(), stones.end(), 0);

        std::vector<std::vector<bool>> dpTable(stones.size() + 1, std::vector<bool>((sum / 2) + 1, false));
        dpTable[0][0] = true;
        for (int i = 1; i <= stones.size(); i++) {
            for(int j = sum / 2; j >= 0; j--) {
                bool withCurrentElement = false;
                if(j >= stones[i-1]) {
                    withCurrentElement = dpTable[i-1][j - stones[i-1]];
                }
                bool withoutCurrentElement = dpTable[i-1][j];
                dpTable[i][j] = withCurrentElement || withoutCurrentElement;
                //std::cout << "i j -> " << i << " " << j << " dpTable[i][j] -> " << dpTable[i][j] << std::endl;
            }
        }

        for(int j = sum / 2; j > 0; j--) {
            if(dpTable[stones.size()][j] == true) {
                return sum - (2 * j);
            }
        }
        return 0;
    }
};

/*
1 1 2 4 7 8 
1 7 2 4 7
1 7 5 4
1 3 5
1 2
1

21 26 31 33 40
21 14 31 33
12 14 31
12 17

*/