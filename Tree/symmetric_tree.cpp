/*
Problem: 101. Symmetric Tree

Problem Description:
Given the root of a binary tree, check whether 
it is a mirror of itself (i.e., symmetric around its center).

Our Approach:
- The core function (isMirror) compares
    the left subtree and the right subtree simultaneously by moving in opposite directions:
    - If both matching positions are missing (nullptr), they mirror each other. Return True.
    - If one side has a node but the other side does not, it is asymmetrical. Return False
    - If both nodes exist but hold different data values, they are not mirror images. Return False.
    - If the current nodes match, we must cross-check their children in reverse order:
        -> Match the outer edges: Compare (left->left) side with the (right->right) side.
        -> Match the inner edges: Compare (left->right) side with the (right->left) side.
        
Time Complexity: O(N)
Space Complexity: O(H) - (where H is the height of the tree)
*/

class Solution {
public:
    bool isMirror(TreeNode* left, TreeNode* right) {
        if (left == nullptr && right == nullptr)
            return true;
        if (left == nullptr || right == nullptr)
            return false;
        if (left->val != right->val)
            return false;

        return isMirror(left->left, right->right) &&
            isMirror(left->right, right->left);
    }

    bool isSymmetric(TreeNode* root) {
        if (root == nullptr)
            return true;
        return isMirror(root->left, root->right);
    }
};