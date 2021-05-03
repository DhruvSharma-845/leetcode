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
//#include "rearrange_words_in_sentence.h"
//#include "sell_diminishing_valued_colored_balls.h"
//#include "remove_covered_intervals.h"
//#include "reveal-cards-in-increasing-order.h"
//#include "binary_search_tree_to_greater_sum_tree.h"
//#include "number_of_provinces.h"
//#include "score_of_parentheses.h"
#include "compare_strings_frequency_smallest_character.h"

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
    /*std::string res = solution.arrangeWords("Jlhvvd wfwnphmxoa qcuucx qsvqskq cqwfypww dyphntfz hkbwx xmwohi qvzegb ubogo sbdfmnyeim tuqppyipb llwzeug hrsaebveez aszqnvruhr xqpqd ipwbapd mlghuuwvec xpefyglstj dkvhhgecd kry");
    std::cout << res << std::endl;*/

    /*std::vector<int> v;
    //v.push_back(1000000000);
    v.push_back(2);
    v.push_back(5);
    v.push_back(8);
    v.push_back(4);
    v.push_back(6);
    v.push_back(10);
    std::cout << solution.maxProfit(v, 4) << std::endl;*/

    /*std::vector<std::vector<int>> intervals{
        {1,4}, {2,3}
    };
    std::cout << solution.removeCoveredIntervals(intervals) << std::endl;*/

    /*std::vector<int> deck{17,13,11,2,3,5,7};
    std::vector<int> finalDeck = solution.deckRevealedIncreasing(deck);
    std::copy(finalDeck.begin(), finalDeck.end(), std::ostream_iterator<int>(std::cout));*/

    /*TreeNode* rll = new TreeNode(0);
    TreeNode* rlr = new TreeNode(2);
    TreeNode* rl = new TreeNode(1, rll, rlr);

    TreeNode* rrl = new TreeNode(5);
    TreeNode* rrr = new TreeNode(7);
    TreeNode* rr = new TreeNode(6, rrl, rrr);
    TreeNode* root = new TreeNode(4, rl, rr);

    inorderTraversal(root);
    TreeNode* rootFinal = solution.bstToGst(root);
    std::cout << "After conversion:" << std::endl;
    inorderTraversal(root);*/

    /*std::vector<std::vector<int>> cities{{1,0,0}, {0,1,0}, {0,0,1}};
    std::cout << solution.findCircleNum(cities) << std::endl;*/

    //std::cout << solution.scoreOfParentheses("(()(()))") << std::endl;

    std::vector<std::string> words{"a","aa","aaa","aaaa"};
    std::vector<std::string> queries{"bbb","cc"};
    std::vector <int> result = solution.numSmallerByFrequency(queries, words);
    std::copy(result.begin(), result.end(), std::ostream_iterator<int>(std::cout, " "));
}