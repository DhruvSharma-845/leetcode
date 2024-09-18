#include <list_node.h>
#include <algorithm>
#include <numeric>

using ListNode = GenericListNode<int>;

class Solution {
public:
    ListNode* insertGreatestCommonDivisors(ListNode* head) {
        ListNode* current = head;
        ListNode* nextNode = current;
        if(current != nullptr) {
            nextNode = current->next;
        }

        while(nextNode != nullptr) {
            int gcdValue = std::gcd(current->val, nextNode->val);
            current->next = new ListNode(gcdValue, nextNode);
            current = nextNode;
            nextNode = current->next;
        }
        return head;
    }
};