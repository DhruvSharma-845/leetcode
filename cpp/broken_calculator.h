
class Solution {
public:
    int brokenCalc(int startValue, int target) {
        auto ans = int{0};
        while(target > startValue) {
            ++ans;
            if(target % 2 == 0) {
                target /= 2;
            }
            else {
                ++target;
            }
        }
        return ans + (startValue - target);      
    }
};