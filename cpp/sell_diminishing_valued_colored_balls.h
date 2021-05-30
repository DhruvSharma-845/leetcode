#include <vector>
#include <algorithm>
#include <functional>
#include <iostream>

using lli = long long int;

class Solution {
public:
    int maxProfit(std::vector<int>& inventory, int orders) {
        std::sort(inventory.begin(), inventory.end(), std::greater<int>());

        int low = 0;
        int high = inventory[0];
        int mid = -1;
        int index = -1;
        while(low <= high) {
            mid = low + (high - low) / 2;
            std::pair<int, int> res = useTillKBalls(inventory, orders, mid);
            if(res.first < 0) {
                high = mid - 1;
            } 
            else if(res.first > 0) {
                low = mid + 1;
            }
            else {
                index = res.second;
                break;
            }
        }
        lli sum = 0;
        for(auto elem: inventory) {
            if(elem < mid) {
                break;
            }
            auto numOfBalls = elem - mid + 1;
            if(index > 0) {
                sum += ((static_cast<lli>(numOfBalls) * (static_cast<lli>(mid) + elem)) / 2);
                std::cout << sum << std::endl;
            }
            else {
                sum += ((static_cast<lli>(numOfBalls - 1) * (static_cast<lli>(mid) + 1 + elem)) / 2);
                std::cout << sum << std::endl;
            }
            index--;
        }
        return sum % 1000000007;
    }

    std::pair<int, int> useTillKBalls(std::vector<int>& inventory, int orders, int K) {
        lli sumOfBalls = 0;
        int index = 0;
        for(auto elem: inventory) {
            if(elem < K) {
                break;
            }
            sumOfBalls += (elem - K + 1);
            ++index;
        }
        if(orders <= sumOfBalls && orders > (sumOfBalls - index)) {
            return {0, index - (sumOfBalls - orders)};
        }
        else if(sumOfBalls > orders) {
            return {1, -1};
        }
        else if(sumOfBalls < orders) {
            return {-1, -1};
        }
        return {0, -1};
    }
};

