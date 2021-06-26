#include <iostream>
#include <vector>
#include <cmath>
#include <limits>

// Recurrence relation:
// T(i, lane) = MIN( T(i-1, lane), 1 + T(i, other_lanes))

int MAX = std::numeric_limits<int>::max();

class Solution {
public:
    int minSideJumps(std::vector<int>& obstacles) {
        int sz = obstacles.size();
        std::vector<std::vector<int>> table(3, std::vector<int>(sz, 0));

        table[0][0] = 1;
        table[1][0] = 0;
        table[2][0] = 1;
        for (int j = 1; j < sz; j++) {
            for (size_t i = 0; i < 3; i++) {
                if(obstacles[j] == i + 1) {
                    table[i][j] = MAX;
                }
                else {
                    int val = MAX;
                    for(int k = 0; k < 3; k++) {
                        if(k == i) {
                            val = std::min(table[k][j-1], val);
                        }
                        else if(obstacles[j-1] != k+1 && (obstacles[j] != k+1 || obstacles[j-1] != i+1)) {
                            val = std::min(table[k][j-1] + 1, val);
                        }
                        std::cout << k << "->" << val << std::endl;
                    }
                    table[i][j] = (val != MAX) ? val : MAX;
                }
                std::cout << i << " " << j << ":" << table[i][j] << std::endl;
            }
        }
        return std::min(std::min(table[0][sz-1], table[1][sz-1]), table[2][sz-1]);
    }
};