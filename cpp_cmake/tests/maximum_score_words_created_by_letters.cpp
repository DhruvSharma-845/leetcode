#include <gtest/gtest.h>
#include <maximum_score_words_created_by_letters.h>

TEST(Maximum_Score_Words_Created_By_Letters, BasicAssertion1) {
    Solution s;
    std::vector<std::string> words{"xxxz","ax","bx","cx"};
    std::vector<char> letters{'z','a','b','c','x','x','x'};
    std::vector<int> score{4,4,4,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,5,0,10};
    auto res = s.maxScoreWords(words, letters, score);
    ASSERT_EQ(res, 27);
}