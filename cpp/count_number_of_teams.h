#include <vector>

class Solution {
public:
    int numTeams(std::vector<int>& rating) {
        std::vector<int> leftSmall(rating.size(), 0);
        std::vector<int> leftLarge(rating.size(), 0);
        for (int i = 1; i < rating.size(); i++) {
            int k = i - 1;
            while(k >= 0) {
                if(rating[k] > rating[i]) {
                    leftLarge[i]++;
                }
                if(rating[k] < rating[i]) {
                    leftSmall[i]++;
                }
                k--;
            }
        }
        
        std::vector<int> rightLarge(rating.size(), 0);
        std::vector<int> rightSmall(rating.size(), 0);
        for (int i = rating.size() - 2; i >= 0; i--) {
            int k = i + 1;
            while(k < rating.size()) {
                if(rating[k] < rating[i]) {
                    rightSmall[i]++;
                }
                if(rating[k] > rating[i]) {
                    rightLarge[i]++;
                }
                k++;
            }
        }

        auto totalCount = int{0};
        for (int i = 0; i < rating.size(); i++) {
            totalCount += (leftSmall[i] * rightLarge[i]);
            totalCount += (leftLarge[i] * rightSmall[i]);
        }
        return totalCount;
    }
};