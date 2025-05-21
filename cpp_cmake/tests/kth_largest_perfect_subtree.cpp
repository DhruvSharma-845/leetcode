//
// Created by Dhruv Sharma on 21/05/25.
//

#include "kth_largest_perfect_subtree.h"

#include <gtest/gtest.h>

TEST(KthLargestPerfectSubtree, Assertion1) {
    TreeNode* root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);
    root->left->left = new TreeNode(4);
    root->left->right = new TreeNode(5);
    root->right->left = new TreeNode(6);
    root->right->right = new TreeNode(7);
    Solution s;
    EXPECT_EQ(s.kthLargestPerfectSubtree(root, 1), 7);
}

TEST(KthLargestPerfectSubtree, Assertion2) {
    TreeNode* root = new TreeNode(10);
    root->left = new TreeNode(6);
    root->right = new TreeNode(2);
    root->left->right = new TreeNode(11);
    root->right->left = new TreeNode(10);
    Solution s;
    EXPECT_EQ(s.kthLargestPerfectSubtree(root, 3), -1);
}
