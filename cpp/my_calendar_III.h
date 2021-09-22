#include <vector>
#include <algorithm>

class Solution {
private:
    std::vector<int> startPoints;
    std::vector<int> endPoints;

    auto findKBooking(const std::vector<int>& starts, const std::vector<int>& ends) -> int {
        int i = 0, j = 0;
        int maxBookings = 0;

        int bookings = 0;
        while(i < starts.size() && j < ends.size()) {
            if(starts[i] <= ends[j]) {
                bookings++;
                i++;
            }
            maxBookings = std::max(bookings, maxBookings);
            if(starts[i] >= ends[j]) {
                bookings--;
                j++;
            }
        }
        return maxBookings;
    }
public:
    Solution() {
        startPoints.reserve(400);
        endPoints.reserve(400);
    }
    
    int book(int start, int end) {
        startPoints.push_back(start);
        std::sort(startPoints.begin(), startPoints.end());

        endPoints.push_back(end);
        std::sort(endPoints.begin(), endPoints.end());

        return findKBooking(startPoints, endPoints);
    }
};