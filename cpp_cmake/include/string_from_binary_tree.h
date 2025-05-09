#ifndef STRING_FROM_BINARY_TREE_H
#define STRING_FROM_BINARY_TREE_H

#include "tree_node.h"

#include <string>

class Solution {
private:
    void treeToStrRecursive(TreeNode* node, std::string& result) {
        //process current node
        result += std::to_string(node->val);

        // left subtree
        if (node->left == nullptr && node->right != nullptr) {
            result += "()";
        }
        else if (node->left != nullptr) {
            result += "(";
            treeToStrRecursive(node->left, result);
            result += ")";
        }

        // right subtree
        if (node->right != nullptr) {
            result += "(";
            treeToStrRecursive(node->right, result);
            result += ")";
        }
    }
public:
    std::string tree2str(TreeNode* root) {
        std::string result{""};
        treeToStrRecursive(root, result);
        return result;
    }
};

#endif //STRING_FROM_BINARY_TREE_H
