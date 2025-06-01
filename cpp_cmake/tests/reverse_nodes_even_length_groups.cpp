//
// Created by Dhruv Sharma on 01/06/25.
//

#include "../include/reverse_nodes_even_length_groups.h"

#include <gtest/gtest.h>

// Demonstrate some basic assertions.
TEST(Reverse_Nodes_Even_Length_Groups, BasicAssertions) {
    Solution s;

    ListNode* head = new ListNode(5);
    head->next = new ListNode(2);
    head->next->next = new ListNode(6);
    head->next->next->next = new ListNode(3);

    ListNode* result = s.reverseEvenLengthGroups(head);

    EXPECT_TRUE(result != nullptr);
    EXPECT_EQ(result->val, 5);

    EXPECT_TRUE(result->next != nullptr);
    EXPECT_EQ(result->next->val, 6);

    EXPECT_TRUE(result->next->next != nullptr);
    EXPECT_EQ(result->next->next->val, 2);

    EXPECT_TRUE(result->next->next->next != nullptr);
    EXPECT_EQ(result->next->next->next->val, 3);
}
