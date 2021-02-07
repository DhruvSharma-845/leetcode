#include <iostream>
#include <iterator>
#include <algorithm>
//#include "shuffle_string.h"
//#include "increasing_decreasing_string.h"
//#include "minimum_subsequence_in_non_increasing_order.h"
//#include "widest_area_between_two_points.h"
//#include "intersection_of_two_arrays_II.h"
//#include "maximum_number_of_coins.h"
//#include "k_closest_points_to_origin.h"
#include "rearrange_words_in_sentence.h"

int main() {
    Solution solution;
    //std::vector<int> v{4,5,6,7,0,2,1,3};
    //std::cout << solution.restoreString("codeleet", v) << std::endl;
    //std::string s = "leetcode";
    //std::cout << solution.sortString(s) << std::endl;

    //std::vector<int> v{4,3,10,9,8};
    //std::vector<int> res = solution.minSubsequence(v);
    //std::copy(res.begin(), res.end(), std::ostream_iterator<int>(std::cout, " "));

    /*std::vector<std::vector<int>> v{
        {10,9}, {8,3}, {7,4}
    };
    std::cout << solution.maxWidthOfVerticalArea(v) << std::endl;*/

    /*std::vector<int> v1{1,2,2,1};
    std::vector<int> v2{2,2};
    std::vector<int> res = solution.intersect(v1, v2);
    std::copy(res.begin(), res.end(), std::ostream_iterator<int>(std::cout, " "));*/

    /*std::vector<int> v{9,8,7,6,5,1,2,3,4};
    std::cout << solution.maxCoins(v) << std::endl;*/

    /*std::vector<std::vector<int>> points{
        {1,3}, {-2,2}
    };
    std::vector<std::vector<int>> kClosestPts = solution.kClosest(points, 1);
    for(auto& elem: kClosestPts) {
        for(auto coord: elem) {
            std::cout << coord << " ";
        }
        std::cout << "\n";
    }*/
    std::string res = solution.arrangeWords("Jlhvvd wfwnphmxoa qcuucx qsvqskq cqwfypww dyphntfz hkbwx xmwohi qvzegb ubogo sbdfmnyeim tuqppyipb llwzeug hrsaebveez aszqnvruhr xqpqd ipwbapd mlghuuwvec xpefyglstj dkvhhgecd kry");
    std::cout << res << std::endl;
}