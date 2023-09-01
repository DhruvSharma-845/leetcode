#include <string>
#include <gtest/gtest.h>
#include <valid_parentheses.h>

TEST(ValidParentheses, BasicAssertions) {
    Solution s;
    ASSERT_TRUE(s.isValid(std::string("()")));
    ASSERT_TRUE(s.isValid(std::string("()[]{}")));
    ASSERT_FALSE(s.isValid(std::string("(]")));
    ASSERT_FALSE(s.isValid(std::string("(()")));
    ASSERT_FALSE(s.isValid(std::string("]")));
}