#include <vector>

class Solution {
public:
    std::vector<int> corpFlightBookings(std::vector<std::vector<int>>& bookings, int n) {
        std::vector<int> temp(n, 0);
        for(int i = 0; i < bookings.size(); i++) {
            temp[bookings[i][0] - 1] += bookings[i][2];
            if(bookings[i][1] < n) {
                temp[bookings[i][1]] -= bookings[i][2];
            }
        }

        std::vector<int> output(n, 0);
        output[0] = temp[0];
        for (int i = 1; i < n; i++) {
            output[i] = output[i-1] + temp[i];
        }
        return output;
    }
};
