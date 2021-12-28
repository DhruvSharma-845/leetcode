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
//#include "compare_strings_frequency_smallest_character.h"
//#include "minimum_limit_of_balls_in_bag.h"
//#include "most_competitive_subsequence.h"
//#include "valid_number.h"
//#include "maximum_area_of_piece_of_cake.h"
//#include "string_break_another_string.h"
//#include "house_robber.h"
//#include "nim_game.h"
//#include "data_stream_disjoint_intervals.h"
//#include "cheapest_flights.h"
//#include "maximum_erasure_value.h"
//#include "push_dominoes.h"
//#include "word_break.h"
//#include "open_the_lock.h"
//#include "reorganize_string.h"
//#include "beautiful_arrangement_II.h"
//#include "remove_adjacent_duplicates_II.h"
//#include "minimum_sideway_jumps.h"
//#include "count_negative_in_sorted_matrix.h"
//#include "insufficient_nodes_root_to_leaf_path.h"
//#include "last_stone_weight.h"
//#include "last_stone_weight_II.h"
//#include "count_number_of_teams.h"
//#include "count_servers_communicate.h"
//#include "uncrossed_lines.h"
//#include "longest_string_chain.h"
//#include "container_with_most_water.h"
//#include "rabbits_in_forest.h"
//#include "corporate_flight_bookings.h"
//#include "broken_calculator.h"
//#include "time_to_inform_all_employees.h"
//#include "divide_array_in_sets_of_k_consecutive_num.h"
//#include "my_calendar_III.h"
//#include "sliding_puzzle.h"
//#include "pallindrome_partitioning_III.h"
//#include "remove_element_to_make_array_increasing.h"
//#include "bulb_switcher_II.h"
//#include "number_of_burgers.h"
//#include "swim_in_rising_water.h"
//#include "two_keys_keyboard.h"
//#include "maximum_length_of_repeated_subarray.h"
//#include "avoid_flood_in_city.h"
//#include "buddy_strings.h"
#include "check_if_word_can_be_placed_in_crossword.h"

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
    v.push_back(2);
    v.push_back(8);
    v.push_back(4);
    v.push_back(6);
    v.push_back(10);
    std::cout << solution.maxProfit(v, 20) << std::endl;*/

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

    /*std::vector<std::string> words{"a","aa","aaa","aaaa"};
    std::vector<std::string> queries{"bbb","cc"};
    std::vector <int> result = solution.numSmallerByFrequency(queries, words);
    std::copy(result.begin(), result.end(), std::ostream_iterator<int>(std::cout, " "));*/

    /*std::vector<int> nums{7,17};
    std::cout << solution.minimumSize(nums, 2) << std::endl;*/
    
    /*std::vector<int> v{2,4,3,3,5,4,9,6};
    std::vector<int> res = solution.mostCompetitive(v, 4);
    std::copy(res.begin(), res.end(), std::ostream_iterator<int>(std::cout, " "));*/

    /*if(solution.isNumber("4e+") == true) {
        std::cout << "Valid Number." << std::endl;
    }
    else {
        std::cout << "Invalid Number!!!" << std::endl;
    }*/
    /*std::vector<int> hCuts{3, 1};
    std::vector<int> vCuts{1};
    std::cout << solution.maxArea(5, 4, hCuts, vCuts) << std::endl;*/

    /*std::string s1{"leetcodee"};
    std::string s2{"interview"};
    if(solution.checkIfCanBreak(s1, s2) == true) {
        std::cout << "Breakable!!!" << std::endl;
    }
    else {
        std::cout << "NotBreakable..." << std::endl;
    }*/

    /*std::vector<int> v{};
    std::cout << solution.rob(v) << std::endl;*/

    /*if(solution.canWinNim(5) == false) {
        std::cout << "We cannot win!" << std::endl;
    }
    else {
        std::cout << "We can win." << std::endl;
    }*/

    /*SummaryRanges sr;
    sr.addNum(1);
    sr.addNum(3);
    sr.addNum(7);
    sr.addNum(2);
    std::vector<std::vector<int>> res = sr.getIntervals();
    for(const auto& v: res) {
        std::cout << v[0] << " -> " << v[1] << std::endl;
    }*/


    /*std::vector<std::vector<int>> fl{
        {0,1,100}, {1,2,100}, {0,2,500}
    };
    std::cout << solution.findCheapestPrice(3, fl, 0, 2, 0) << std::endl;*/

    /*std::vector<int> v{4,2,4,5,6};
    std::cout << solution.maximumUniqueSubarray(v) << std::endl;*/
    
    /*std::string s{".L.R...LR..L.."};
    std::cout << solution.pushDominoes(s) << std::endl;*/

    /*std::vector<std::string> v{"cats","dog","sand","and","cat", "an"};
    std::string s{"catsandog"};
    if(solution.wordBreak(s, v)) {
        std::cout << "Breakable" << std::endl;
    }
    else {
        std::cout << "Not Breakable" << std::endl;
    }*/

    /*std::vector<std::string> v{"8887","8889","8878","8898","8788","8988","7888","9888"};
    std::string s{"8888"};
    std::cout << solution.openLock(v, s) << std::endl;*/

    /*std::string s{"aab"};
    std::cout << solution.reorganizeString(s) << std::endl;*/

    /*auto res = solution.constructArray(5, 3);
    std::copy(res.begin(), res.end(), std::ostream_iterator<int>(std::cout, " "));*/

    /*std::string s{"deeedbbcccbdaa"};
    std::cout << solution.removeDuplicates(s, 3) << std::endl;*/

    /*std::vector<int> obs{0,1,2,3,0};
    std::cout << solution.minSideJumps(obs) << std::endl;*/

    //std::vector<std::vector<int>> matrix{
    /*    {4,3,2,-1},
        {3,2,1,-1},
        {1,1,-1,-2},
        {-1,-1,-2,-3}*/
    /*    {-1, -1},
        {-1, -2}
    };
    std::cout << solution.countNegatives(matrix) << std::endl;*/

    /*TreeNode* root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(-2);

    TreeNode* r = solution.sufficientSubset(root, 1);
    std::cout << r->val << std::endl;*/

    /*std::vector<int> v{2, 7, 4, 1, 8, 1};
    std::cout << solution.lastStoneWeight(v) << std::endl;*/

    /*std::vector<int> v{2,7,4,1,8,1};
    std::cout << solution.lastStoneWeightII(v) << std::endl;*/

    /*std::vector<int> v{2,5,3,4,1};
    std::cout << solution.numTeams(v) << std::endl;*/

    /*std::vector<std::vector<int>> v{
        {1,0},
        {1,1}
    };
    std::cout << solution.countServers(v) << std::endl;*/

    /*std::vector<int> v1{1,4,2};
    std::vector<int> v2{1,2,4};

    std::cout << solution.maxUncrossedLines(v1, v2) << std::endl;*/

    /*std::vector<std::string> words{"xbc","pcxbcf","xb","cxbc","pcxbc"};
    std::cout << solution.longestStrChain(words) << std::endl;*/

    /*std::vector<int> v{1,8,6,2,5,4,8,3,7};
    std::cout << solution.maxArea(v) << std::endl;*/

    /*std::vector<int> v{1,1,3,3};
    std::cout << solution.numRabbits(v) << std::endl;*/

    /*std::vector<std::vector<int>> v{
        {1,2,10},
        {2,3,20},
        {2,5,25}
    };
    std::vector<int> res = solution.corpFlightBookings(v, 5);
    std::copy(res.begin(), res.end(), std::ostream_iterator<int>(std::cout, " "));*/

    /*std::cout << solution.brokenCalc(5, 12) << std::endl;*/

    /*std::vector<int> managers{-1,0,0,1,1,2,2,3,3,4,4,5,5,6,6};
    std::vector<int> informTime{1,1,1,1,1,1,1,0,0,0,0,0,0,0,0};
    std::cout << solution.numOfMinutes(15, 0, managers, informTime) << std::endl;*/

    /*std::vector<int> v{3,2,1,2,3,4,3,4,5,9,10,11};
    if(solution.isPossibleDivide(v, 3) == true) {
        std::cout << "Yes" << std::endl;
    }
    else {
        std::cout << "No" << std::endl;
    }*/

    /*std::cout << solution.book(10, 20) << std::endl;
    std::cout << solution.book(50, 60) << std::endl;
    std::cout << solution.book(5, 20) << std::endl;*/

    /*std::vector<std::vector<int>> v{
        {4,1,2}
        ,{5,0,3}
    };
    std::cout << solution.slidingPuzzle(v) << std::endl;*/

    /*std::string s{"leetcode"};
    std::cout << solution.palindromePartition(s, 8) << std::endl;*/

    /*std::vector<int> v{1,2,10,5,7};
    if(solution.canBeIncreasing(v)) {
        std::cout << "Can be made increasing." << std::endl;
    }  
    else {
        std::cout << "Cannot be made increasing!!!" << std::endl;
    }*/

    //std::cout << solution.flipLights(3, 1) << std::endl;

    /*auto x = solution.numOfBurgers(16, 7);
    std::copy(x.begin(), x.end(), std::ostream_iterator<int>(std::cout, " "));*/

    /*std::vector<std::vector<int>> pool{
        {0,1,2,3,4},
        {24,23,22,21,5},
        {12,13,14,15,16},
        {11,17,18,19,20},
        {10,9,8,7,6}
    };
    std::cout << solution.swimInWater(pool) << std::endl;*/

    //std::cout << solution.minSteps(3) << std::endl;

    /*std::vector<int> v{1,2,3,1,2};
    std::vector<int> v1{1,2,1,2,3};
    std::cout << solution.findLength(v, v1) << std::endl;*/

    /*std::vector<int> v{1,2,0,1,3};
    auto ans = solution.avoidFlood(v);
    std::copy(ans.begin(), ans.end(), std::ostream_iterator<int>(std::cout, " "));*/

    /*if(solution.buddyStrings("aa", "aa")) {
        std::cout << "Buddy Strings!" << std::endl;
    }
    else {
        std::cout << "Not buddy!!!" << std::endl;
    }*/

    std::vector<std::vector<char>> board{
        {' ', ' ', 'd'}, 
        {' ', ' ', '#'}, 
        {' ', 'c', 'b'}
    };
    if(solution.placeWordInCrossword(board, "abc")) {
        std::cout << "Can be placed!" << std::endl;
    }
    else {
        std::cout << "Cannot be placed!!!" << std::endl;
    }
}