#include <vector>
#include <algorithm>
#include <limits>

class Solution {
public:
    bool escapeGhosts(std::vector<std::vector<int>>& ghosts, std::vector<int>& target) {
        int steps = abs(target[1]) + abs(target[0]);

        int minSteps = std::numeric_limits<int>::max();
        for(const auto& ghost: ghosts) {
            minSteps = std::min(minSteps, abs(ghost[1] - target[1]) + abs(ghost[0] - target[0])); 
        }
        return (minSteps > steps);
    }
};