#include <iostream>
#include <limits>
#include <algorithm>

class Solution {
private:
    int findCost(int startAt, int moveCost, int pushCost, int mins, int secs) {
        int minFirstDigit = mins / 10;
        int minSecondDigit = mins % 10;
        
        int secFirstDigit = secs / 10;
        int secSecondDigit = secs % 10;
        
        int cost = 0;
        bool isFirstDigitUsed = false; 
        if(minFirstDigit != 0) {
            if(startAt != minFirstDigit) {
                cost += (moveCost + pushCost);
                startAt = minFirstDigit;
            }
            else {
                cost += pushCost;
            }
            isFirstDigitUsed = true;
        }
        
        if(minSecondDigit != 0 || (minSecondDigit == 0 && isFirstDigitUsed)) {
            if(startAt != minSecondDigit) {
                cost += (moveCost + pushCost);
                startAt = minSecondDigit;
            }
            else {
                cost += pushCost;
            }
            isFirstDigitUsed = true;
        }
        
        if(secFirstDigit != 0 || (secFirstDigit == 0 && isFirstDigitUsed)) {
            if(startAt != secFirstDigit) {
                cost += (moveCost + pushCost);
                startAt = secFirstDigit;
            }
            else {
                cost += pushCost;
            }
            isFirstDigitUsed = true;
        }
        
        if(secSecondDigit != 0 || (secSecondDigit == 0 && isFirstDigitUsed)) {
            if(startAt != secSecondDigit) {
                cost += (moveCost + pushCost);
                startAt = secSecondDigit;
            }
            else {
                cost += pushCost;
            }
            isFirstDigitUsed = true;
        }
        return cost;
        
    }
public:
    int minCostSetTime(int startAt, int moveCost, int pushCost, int targetSeconds) {
        //initial attempt
        int minsF = targetSeconds / 60;
        int secsF = targetSeconds % 60;
        
        int result = std::numeric_limits<int>::max();
        if(minsF <= 99) {
            result = std::min(result, findCost(startAt, moveCost, pushCost, minsF, secsF)); 
        }
        
        //std::cout << result << std::endl;
        
        if(minsF > 0) {
            --minsF;
            secsF = targetSeconds - (minsF * 60); 
            //std::cout << minsF << " " << secsF << std::endl;
            if(secsF <= 99) {
                result = std::min(result, findCost(startAt, moveCost, pushCost, minsF, secsF));
            }
        }
        return result;
    }
};