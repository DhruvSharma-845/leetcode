//
// Created by Dhruv Sharma on 01/06/25.
//

#ifndef REVERSE_NODES_EVEN_LENGTH_GROUPS_H
#define REVERSE_NODES_EVEN_LENGTH_GROUPS_H

#include "list_node.h"
#include <vector>

class Solution {
public:
    ListNode* reverseEvenLengthGroups(ListNode* head) {
        ListNode* current = head;

        int currentNaturalNumber = 1;
        std::vector<int> values;
        while (current != nullptr) {
            int length = currentNaturalNumber;
            ListNode* node = current;

            values.resize(length);
            while (length > 0 && node != nullptr) {
                values[length - 1] = node->val;
                node = node->next;
                --length;
            }

            bool reverseValue = (((currentNaturalNumber - length)  % 2) == 0);
            if (reverseValue) {
                length = currentNaturalNumber;
                node = current;
                int index = 0;
                while (length > 0 && node != nullptr) {
                    node->val = values[index++];
                    node = node->next;
                    --length;
                }
            }

            current = node;
            ++currentNaturalNumber;
        }
        return head;
    }
};

#endif //REVERSE_NODES_EVEN_LENGTH_GROUPS_H
