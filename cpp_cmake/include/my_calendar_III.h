#include <vector>
#include <algorithm>

class MyCalendarThree {
private:
    std::vector<int> startTimes;
    std::vector<int> endTimes;
public:
    MyCalendarThree() {
        
    }
    
    int book(int startTime, int endTime) {
        startTimes.push_back(startTime);
        endTimes.push_back(endTime);

        std::sort(startTimes.begin(), startTimes.end());
        std::sort(endTimes.begin(), endTimes.end());

        int startIndex = 0;
        int endIndex = 0;

        int currentMaxCount = 0;
        int maxCount = 0;
        while(startIndex < startTimes.size() && endIndex < endTimes.size()) {
            if(startTimes[startIndex] < endTimes[endIndex]) {
                ++startIndex;
                ++currentMaxCount;
            }
            else {
                ++endIndex;
                --currentMaxCount;
            }
            maxCount = std::max(maxCount, currentMaxCount);
        }
        return maxCount;
    }
};

/**
 * Your MyCalendarThree object will be instantiated and called as such:
 * MyCalendarThree* obj = new MyCalendarThree();
 * int param_1 = obj->book(startTime,endTime);
 */