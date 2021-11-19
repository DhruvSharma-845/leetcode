#include <cmath>

class Solution {
public:
    int minSteps(int n) {
        if(n == 1) {
            return 0;
        }

        int i = (n / 2); 
        for(; i > 0; --i) {
            if(n % i == 0) {
                break;
            }
        }
        return (n / i) + minSteps(i);
    }
};