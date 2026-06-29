/*
Problem: 111. Minimum Depth of Binary Tree

Problem Description:
Given a binary tree, find its minimum depth.
The minimum depth is the number of nodes along the shortest path
from the root node down to the nearest leaf node.
Note: A leaf is a node with no children.

Our Approach:
- Base Case (Empty Tree): If the current node is missing (nullptr), its height is 0. Return 0.
- Find the minimum depth of the left subtree and the right subtree.
- The Skewed Tree Rule : 
    If either the left or right depth is 0, it means the current node is not a leaf node
        yet (it still has a child on the other side). So we cannot top here.
        So, pick the larger depth, add 1 for the current node, and return it.
- If both depths are greater than 0, we have a true choice between two paths.
    Pick the smaller depth, add 1 for the current node, and return it.
        
Time Complexity: O(N)
Space Complexity: O(H) - (where H is the height of the tree)
*/

class Solution {
public:
    int minDepth(TreeNode* root) {
        if (root == nullptr)
            return 0;

        int leftHeight = minDepth(root->left);
        int rightHeight = minDepth(root->right);

        if (leftHeight == 0 || rightHeight == 0)
            return 1 + std::max(leftHeight, rightHeight);
        else
            return 1 + std::min(leftHeight, rightHeight);
    }
};