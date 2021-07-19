struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution {
private:
    auto sufficientSubsetUtil(TreeNode* node, int currentPathSum, int limit) -> bool {
        if(node->left == nullptr && node->right == nullptr) {
            return (currentPathSum >= limit);
        }
        bool leftRes = false;
        if(node->left != nullptr) {
            leftRes = sufficientSubsetUtil(node->left, currentPathSum + node->val, limit);
        }
        if(leftRes == false) {
            delete node->left;
            node->left = nullptr;
        }

        bool rightRes = false;
        if(node->right != nullptr) {
            rightRes = sufficientSubsetUtil(node->right, currentPathSum + node->val, limit);
        }
        if(rightRes == false) {
            delete node->right;
            node->right = nullptr;
        }
        return leftRes || rightRes;
    }
public:
    TreeNode* sufficientSubset(TreeNode* root, int limit) {
        if(sufficientSubsetUtil(root, root->val, limit) == false) {
            delete root;
            root = nullptr;
        };
        return root;
    }
};