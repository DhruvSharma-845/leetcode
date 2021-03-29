#include <vector>
#include <algorithm>
#include <functional>

class Solution {
public:
    int maxProfit(std::vector<int>& inventory, int orders) {
        std::sort(inventory.begin(), inventory.end(), std::greater<int>());

        int low = 0;
        int high = inventory[0];
        int mid = -1;
        while(low < high) {
            mid = low + (high - low) / 2;
            int res = useKBalls(inventory, orders, mid);
            if(res < 0) {
                high = mid - 1;
            } 
            else if(res > 0) {
                low = mid + 1;
            }
            else {
                break;
            }
        }
        long long int sum = 0;
        for(auto elem: inventory) {
            if(elem < mid) {
                break;
            }
            sum += ((elem - mid) % 1000000007);
        }
        return sum;
    }

    int useKBalls(std::vector<int>& inventory, int orders, int K) {
        int sum = 0;
        int index = 0;
        // 5 2
        for(auto elem: inventory) {
            if(elem < K) {
                break;
            }
            sum += (elem - K);
            ++index;
        }
        if(orders - sum < 0) {
            return -1;
        }
        else if(orders - sum > 0) {
            if(orders - sum <= index) {
                return 0;
            }
            return 1;
        }
        else {
            return 0;
        }
    }
};