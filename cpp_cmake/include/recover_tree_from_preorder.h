#include <string>
#include <iostream>
#include "tree_node.h"

class Solution {
private:
    auto recoverFromPreorderUtil(const std::string& traversal, int& currentIndex, int level) -> TreeNode* {
        int newIndex = currentIndex;
        int val = 0;
        while(newIndex < traversal.size() && traversal[newIndex] != '-') {
            val = val * 10 + (traversal[newIndex] - '0');
            ++newIndex;
        }
        TreeNode* node = new TreeNode(val);
        currentIndex = newIndex;

        // recurse for left if enough hyphens
        int hyphenCount = 0;
        while(newIndex < traversal.size() && traversal[newIndex] == '-') {
            ++hyphenCount;
            ++newIndex;
        }
        if(hyphenCount == level + 1) {
            currentIndex = newIndex;
            node->left = this->recoverFromPreorderUtil(traversal, currentIndex, level + 1);
        }
        else {
            node->left = nullptr;
        }

        // recurse for right if enough hyphens
        newIndex = currentIndex;
        hyphenCount = 0;
        while(newIndex < traversal.size() && traversal[newIndex] == '-') {
            ++hyphenCount;
            ++newIndex;
        }
        if(hyphenCount == level + 1) {
            currentIndex = newIndex;
            node->right = this->recoverFromPreorderUtil(traversal, currentIndex, level + 1);
        }
        else {
            node->right = nullptr;
        }
        return node;
    }
public:
    TreeNode* recoverFromPreorder(std::string traversal) {
        int index = 0;
        return this->recoverFromPreorderUtil(traversal, index, 0);
    }
};