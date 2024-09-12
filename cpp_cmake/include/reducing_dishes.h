#include <vector>
#include <algorithm>

class Solution {
public:
    int maxSatisfaction(std::vector<int>& satisfaction) {
        std::sort(satisfaction.begin(), satisfaction.end());

        int elementsSum = 0;
        int likeCoefficient = 0;
        int numOfElements = 0;
        for(int i = satisfaction.size() - 1; i >= 0; --i) {
            if(satisfaction[i] >= 0) {
                likeCoefficient += (satisfaction[i] + elementsSum);
                elementsSum += satisfaction[i];
            }
            else {
                int newLikeCoefficient = likeCoefficient + (elementsSum + satisfaction[i]);
                if(newLikeCoefficient > likeCoefficient) {
                    likeCoefficient = newLikeCoefficient;
                    elementsSum += satisfaction[i];
                }
                else {
                    break;
                }
            }
        }
        return likeCoefficient;
    }
};