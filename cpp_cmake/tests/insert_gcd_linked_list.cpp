#include <vector>
#include <list_node.h>
#include <gtest/gtest.h>

#include <insert_gcd_linked_list.h>

TEST(Insert_GCD_LinkedList, Assertion1) {
    Solution s;

    ListNode* head = new ListNode(18, nullptr);
    head->next = new ListNode(6, nullptr);
    head->next->next = new ListNode(10, nullptr);
    head->next->next->next = new ListNode(3, nullptr);
    auto* newHead = s.insertGreatestCommonDivisors(head);
    ASSERT_NE(newHead, nullptr);

    std::vector<int> expectedRes{18,6,6,2,10,1,3};

    for(const auto& expectedElement: expectedRes) {
        EXPECT_EQ(expectedElement, newHead->val);
        newHead = newHead->next;
        if(newHead == nullptr) {
            break;
        }
    }
}

TEST(Insert_GCD_LinkedList, Assertion2) {
    Solution s;

    ListNode* head = new ListNode(7, nullptr);
    auto* newHead = s.insertGreatestCommonDivisors(head);
    ASSERT_NE(newHead, nullptr);

    std::vector<int> expectedRes{7};

    for(const auto& expectedElement: expectedRes) {
        EXPECT_EQ(expectedElement, newHead->val);
        newHead = newHead->next;
        if(newHead == nullptr) {
            break;
        }
    }
}