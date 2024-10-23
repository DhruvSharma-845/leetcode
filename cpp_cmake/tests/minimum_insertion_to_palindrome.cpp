#include <minimum_insertion_to_palindrome.h>

#include <gtest/gtest.h>

// Demonstrate some basic assertions.
TEST(Minimum_Insertion_To_Make_String_Palindrome, BasicAssertions1) {
  Solution s;
  EXPECT_EQ(2, s.minInsertions("mbadm"));
}