#include "string_from_binary_tree.h"

#include <gtest/gtest.h>
#include "tree_node.h"

auto createTree() -> std::unique_ptr<TreeNode> {
    std::unique_ptr<TreeNode> root = std::make_unique<TreeNode>();
    root->val = 1;

    root->left = new TreeNode(2);
    root->right = new TreeNode(3);

    root->left->left = new TreeNode(4);

    return root;
}

TEST(ConstructStringFromBinaryTree, Assertion1) {
    Solution s;
    auto root = createTree();
    EXPECT_EQ(s.tree2str(root.get()), std::string("1(2(4))(3)"));
}
