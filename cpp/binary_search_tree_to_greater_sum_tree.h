#include <iostream>

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

void inorderTraversal(TreeNode* node) {
    if(node != nullptr) {
        inorderTraversal(node->left);
        std::cout << node->val << std::endl;
        inorderTraversal(node->right);
    }
}

class Solution {
private:
    void bstToGstUtil(TreeNode* node, int* result);    
public:
    TreeNode* bstToGst(TreeNode* root) {
        int sum = 0;
        bstToGstUtil(root, &sum);
        return root;
    }
};

void Solution::bstToGstUtil(TreeNode* node, int* result) {
    if(node->left == nullptr && node->right == nullptr) {
        (*result) = (*result) + node->val;
        node->val = (*result);
        return;
    }
    if(node->right != nullptr) {
        bstToGstUtil(node->right, result);
    }
    (*result) = (*result) + node->val;
    node->val = (*result);
    
    if(node->left != nullptr) {
        bstToGstUtil(node->left, result);
    }
}