#include <string>
#include <vector>

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
    enum class Direction {
      LEFT, RIGHT  
    };
    
    TreeNode* findCommonAncestor(TreeNode* root, int startValue, int destValue) {
        if(root == nullptr) {
            return nullptr;
        }
        if(root->val == startValue || root->val == destValue) {
            return root;
        }
        TreeNode* leftSideAncestor = findCommonAncestor(root->left, startValue, destValue);
        TreeNode* rightSideAncestor = findCommonAncestor(root->right, startValue, destValue);
        if(rightSideAncestor != nullptr && leftSideAncestor != nullptr) {
            return root;
        }
        if(leftSideAncestor != nullptr) {
            return leftSideAncestor;
        }
        if(rightSideAncestor != nullptr) {
            return rightSideAncestor;
        }
        return nullptr;
    }
    
    bool findPathFromLCA(TreeNode* node, int val, std::vector<Direction>& vec) {
        if(node == nullptr) {
            return false;
        }
        if(node->val == val) {
            return true;
        }
        if(findPathFromLCA(node->left, val, vec) == true) {
            vec.push_back(Direction::LEFT);
            return true;
        }
        if(findPathFromLCA(node->right, val, vec) == true) {
            vec.push_back(Direction::RIGHT);
            return true;
        }
        return false;
    }
    
public:
    std::string getDirections(TreeNode* root, int startValue, int destValue) {
        TreeNode* ancestor = findCommonAncestor(root, startValue, destValue);
        
        std::string shortestPath{""};
        std::vector<Direction> directionsStart;
        findPathFromLCA(ancestor, startValue, directionsStart);
        
        for(const auto& dir: directionsStart) {
            shortestPath += "U";
        }
        
        std::vector<Direction> directionsDest;
        findPathFromLCA(ancestor, destValue, directionsDest);
        for(auto it = directionsDest.rbegin(); it != directionsDest.rend(); ++it) {
            if(*it == Direction::LEFT) {
                shortestPath += "L";
            }
            else {
                shortestPath += "R";
            }
        }
        return shortestPath;
    }
};