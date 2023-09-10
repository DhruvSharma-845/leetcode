#include <vector>
#include <string>

class Solution {
public:
    std::vector<int> minOperations(std::string boxes) {
        std::vector<int> rightSum(boxes.size(), 0);
        int currentBalls = (boxes[boxes.size() - 1] == '1') ? 1 : 0;
        for(int i = boxes.size() - 2; i >= 0; --i) {
            rightSum[i] = (rightSum[i+1]) + currentBalls;
            currentBalls += (boxes[i] == '1') ? 1 : 0;
        }

        std::vector<int> totalSum(boxes.size(), 0);
        totalSum[0] = rightSum[0];
        int leftSum = 0;
        currentBalls = (boxes[0] == '1') ? 1 : 0;
        for(int i = 1; i < boxes.size(); ++i) {
            leftSum = leftSum + currentBalls;
            currentBalls += (boxes[i] == '1') ? 1 : 0;
            totalSum[i] = leftSum + rightSum[i];
        }
        return totalSum;
    }
};