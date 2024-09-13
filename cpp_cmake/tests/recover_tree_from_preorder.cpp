#include <recover_tree_from_preorder.h>
#include <tree_node.h>
#include <gtest/gtest.h>

TEST(Recover_Tree_From_Preorder, BasicAssertion1) {
    std::string str = "1-2--3--4-5--6--7";
    Solution s;
    TreeNode* root = s.recoverFromPreorder(str);
    EXPECT_EQ(root->val, 1);
    EXPECT_EQ(root->left->val, 2);
    EXPECT_EQ(root->right->val, 5);
    EXPECT_EQ(root->left->left->val, 3);
    EXPECT_EQ(root->left->right->val, 4);
    EXPECT_EQ(root->right->left->val, 6);
    EXPECT_EQ(root->right->right->val, 7);
}