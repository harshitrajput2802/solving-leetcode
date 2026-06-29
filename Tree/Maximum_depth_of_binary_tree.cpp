/*
Problem: 104. Maximum Depth of Binary Tree

Problem Description:
Given the root of a binary tree, return its maximum depth.
A binary tree's maximum depth is the number of nodes along the 
longest path from the root node down to the farthest leaf node.

Our Approach:
- Base Case (Empty Tree): If the current node is missing (nullptr), its height is 0. Return 0.
- Travel all the way down the left side to find the maximum height of the left subtree.
- Travel all the way down the right side to find the maximum height of the right subtree.
- Compare both calculated heights, pick the larger one, and 
    add 1 to account for the current node. Return this total.
        
Time Complexity: O(N)
Space Complexity: O(H) - (where H is the height of the tree)
*/

class Solution {
public:
    int maxDepth(TreeNode* root) {
        if (root == nullptr)
            return 0;
        int leftHeight = maxDepth(root->left);
        int rightHeight = maxDepth(root->right);
        return 1 + std::max(leftHeight, rightHeight);
    }
};