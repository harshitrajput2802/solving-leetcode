/*
Problem: 100. Same Tree

Problem Description:
Given the roots of two binary trees p and q,
write a function to check if they are the same or not.
Two binary trees are considered the same if 
they are structurally identical, and the nodes have the same value.

Our Approach:
- If both current nodes are missing (nullptr), they match -> Return True.
- If one node exists but the other is missing, the structures differ -> Return False.
- If both nodes exist but hold different data values, they are not identical -> Return False.
- If the current nodes match, repeat these exact same steps for their left subtrees and right subtrees.
Both sides must return True for the overall trees to be considered identical.

Time Complexity: O(N)
Space Complexity: O(H) - (where H is the height of the tree)
*/

class Solution {
public:
    bool isSameTree(TreeNode* p, TreeNode* q) {
        if (p == nullptr && q == nullptr)
            return true;
        if (p == nullptr || q == nullptr)
            return false;
        if (p->val != q->val)
            return false;
        return isSameTree(p->left, q->left) && isSameTree(p->right, q->right);
    }
};