//
// Created by Dhruv Sharma on 19/05/25.
//

#include "complete_binary_tree_inserter.h"

#include <gtest/gtest.h>

TEST(CompleteBinaryTreeInserter, Assertion1) {
    TreeNode* root = new TreeNode(1);
    root->left = new TreeNode(2);
    CBTInserter* obj = new CBTInserter(root);
    int param_1 = obj->insert(3);
    EXPECT_EQ(param_1, 1);
    int param_2 = obj->insert(4);
    EXPECT_EQ(param_2, 2);
    TreeNode* param_3 = obj->get_root();
    EXPECT_NE(param_3, nullptr);
    EXPECT_NE(param_3->right, nullptr);
    EXPECT_EQ(param_3->right->val, 3);
}
