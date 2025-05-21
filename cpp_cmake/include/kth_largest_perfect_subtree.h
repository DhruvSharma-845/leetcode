//
// Created by Dhruv Sharma on 21/05/25.
//

#ifndef KTH_LARGEST_PERFECT_SUBTREE_H
#define KTH_LARGEST_PERFECT_SUBTREE_H

#include "tree_node.h"

#include <vector>
#include <queue>

class Solution {
private:
    bool calculateAllPerfectSubtreeSizes(
        TreeNode* node,
        int k,
        std::priority_queue<int, std::vector<int> , std::greater<int>>& subtreeSizes,
        int& treeSize,
        int & treeHeight) {

        if (node == nullptr) {
            return false;
        }
        if (node->left == nullptr && node->right == nullptr) {
            treeSize = 1;
            treeHeight = 1;
            if (subtreeSizes.size() < k) {
                subtreeSizes.push(treeSize);
            }
            else {
                if (subtreeSizes.top() < treeSize) {
                    subtreeSizes.pop();
                    subtreeSizes.push(treeSize);
                }
            }
            return true;
        }
        int leftTreeSize = 0;
        int leftTreeHeight = 0;
        bool isLeftTreePerfect = calculateAllPerfectSubtreeSizes(node->left, k, subtreeSizes, leftTreeSize, leftTreeHeight);

        int rightTreeSize = 0;
        int rightTreeHeight = 0;
        bool isRightTreePerfect = calculateAllPerfectSubtreeSizes(node->right, k, subtreeSizes, rightTreeSize, rightTreeHeight);

        treeSize = leftTreeSize + rightTreeSize + 1;
        treeHeight = std::max(leftTreeHeight, rightTreeHeight) + 1;
        if (isLeftTreePerfect && isRightTreePerfect && leftTreeHeight == rightTreeHeight) {
            if (subtreeSizes.size() < k) {
                subtreeSizes.push(treeSize);
            }
            else {
                if (subtreeSizes.top() < treeSize) {
                    subtreeSizes.pop();
                    subtreeSizes.push(treeSize);
                }
            }
            return true;
        }
        return false;
    }
public:
    int kthLargestPerfectSubtree(TreeNode* root, int k) {
        std::priority_queue<int, std::vector<int>, std::greater<int>> pq;
        int treeSize = 0;
        int treeHeight = 0;
        calculateAllPerfectSubtreeSizes(root, k, pq, treeSize, treeHeight);
        return k <= pq.size() ? pq.top(): -1;
    }
};


#endif //KTH_LARGEST_PERFECT_SUBTREE_H
