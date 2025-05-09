#include <vector>
#include <utility>

class Solution {
private:
    bool checkForValidCutsWithCoordinates(std::vector<std::pair<int, int>>& markings) {
        std::sort(markings.begin(), markings.end(), [](const auto& a, const auto& b) {
            if(a.first == b.first) {
                return a.second < b.second;
            }
            return a.first < b.first;
        });

        int currentRectangles = 1;
        int boundaries = 0;
        for(int j = 1; j < markings.size(); ++j) {
            // end
            if(markings[j].second == 0) {
                --currentRectangles;
                if(currentRectangles == 0) {
                    ++boundaries;
                }
            }

            // start
            if(markings[j].second == 1) {
                ++currentRectangles;
            }
        }

        if(boundaries >= 3) {
            return true;
        }
        return false;
    }
public:
    bool checkValidCuts(int n, std::vector<std::vector<int>>& rectangles) {
        std::vector<std::pair<int, int>> yMarkings;
        yMarkings.reserve(2 * rectangles.size());

        std::vector<std::pair<int, int>> xMarkings;
        xMarkings.reserve(2 * rectangles.size());
        
        for(const auto& rectangle: rectangles) {
            yMarkings.push_back(std::make_pair(rectangle[1], 1));
            yMarkings.push_back(std::make_pair(rectangle[3], 0));
            xMarkings.push_back(std::make_pair(rectangle[0], 1));
            xMarkings.push_back(std::make_pair(rectangle[2], 0));
        }

        // checking for horizontal cuts
        
        if(checkForValidCutsWithCoordinates(yMarkings) == true) {
            return true;
        }

        // checking for vertical cuts
        
        if(checkForValidCutsWithCoordinates(xMarkings) == true) {
            return true;
        }

        return false;
    }
};