#include <vector>


class Solution {
public:
    std::vector<int> numOfBurgers(int tomatoSlices, int cheeseSlices) {
        std::vector<int> res;
        int y = 4 * cheeseSlices - tomatoSlices;
        if(y < 0 || y % 2 != 0) {
            return res;
        }
        y = y / 2;
        if(cheeseSlices - y < 0) {
            return res;
        }
        res.push_back(cheeseSlices - y);
        res.push_back(y);
        return res;
    }
};


/*

 y = (4*cheeseSlices - tomatoSlices) / 2;
 x = cheeseSlices - y

*/
