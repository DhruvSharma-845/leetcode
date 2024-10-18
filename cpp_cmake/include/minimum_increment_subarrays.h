#include <vector>
#include <limits>
#include <queue>
#include <tuple>

class Solution {
public:
    int minNumberOperations(std::vector<int>& target) {
        int operations = target[0];
        for(int i = 1; i < target.size(); ++i) {
            operations += std::max(target[i] - target[i-1], 0);
        }
        return operations;
    }
};