#include <vector>
#include <algorithm>

class Solution {
public:
    int maxArea(std::vector<int>& height) {
        auto low = int{0};
        auto high = height.size() - 1;

        int area = std::min(height[low], height[high]) * (high - low);

        while(low < high) {
            if(height[low] < height[high]) {
                int leftHeight = height[low];
                ++low;
                while(low < high && height[low] <= leftHeight) {
                    low++;
                }
            }
            else {
                int rightHeight = height[high];
                --high;
                while(low < high && height[high] <= rightHeight) {
                    --high;
                }
            }
            if(low < high) {
                int currentArea = std::min(height[low], height[high]) * (high - low);
                area = std::max(area, currentArea);
            }
        }
        return area;
    }
};