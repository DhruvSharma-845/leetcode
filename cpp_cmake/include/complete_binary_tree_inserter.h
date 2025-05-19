//
// Created by Dhruv Sharma on 19/05/25.
//

#ifndef COMPLETE_BINARY_TREE_INSERTER_H
#define COMPLETE_BINARY_TREE_INSERTER_H

#include "tree_node.h"

#include <queue>

class CBTInserter {
private:
    std::queue<TreeNode*> que;
    TreeNode* root;

    TreeNode* getNext() {
        while (!que.empty()) {
            TreeNode* current = que.front();

            if (current->left != nullptr) {
                que.push(current->left);
            }
            else {
                return current;
            }

            if (current->right != nullptr) {
                que.push(current->right);
            }
            else {
                return current;
            }
            que.pop();
        }
        return nullptr;
    }
public:
    CBTInserter(TreeNode* root): root{root} {
        que.push(root);
        getNext();
    }

    int insert(int val) {
        TreeNode* current = this->getNext();
        if (current != nullptr) {
            if (current->left == nullptr) {
                current->left = new TreeNode(val);
            }
            else if (current->right == nullptr) {
                current->right = new TreeNode(val);
            }
            return current->val;
        }
        return -1;
    }

    TreeNode* get_root() {
        return this->root;
    }
};

#endif //COMPLETE_BINARY_TREE_INSERTER_H
