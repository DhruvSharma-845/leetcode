#include <vector>
#include <unordered_map>

class Solution {
public:
    int numRabbits(std::vector<int>& answers) {
        std::unordered_map<int, int> freq;
        for(auto ans: answers) {
            freq[ans]++;
        }

        auto minRabbits = int{0};
        for(const auto& pr: freq) {
            int temp = static_cast<int>(std::ceil(pr.second / (static_cast<float>(pr.first) + 1)));

            int rabbits = temp * (pr.first + 1);
            minRabbits += rabbits;
        }
        return minRabbits;
    }
};