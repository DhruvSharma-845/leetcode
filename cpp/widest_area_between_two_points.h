#include <vector>
#include <algorithm>

class Solution {
public:
    int maxWidthOfVerticalArea(std::vector<std::vector<int>>& points) {
        std::sort(points.begin(), points.end(), [](std::vector<int>& a, std::vector<int>& b) {
           return a[0] < b[0]; 
        });
        
        int maxDist = 0;
        
        for(int i = 1; i < points.size(); ++i) {
            if(points[i][0] - points[i-1][0] > maxDist) {
                maxDist = points[i][0] - points[i-1][0];
            }
        }
        
        return maxDist;
    }
};