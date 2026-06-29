/*
Problem: 94. Binary Tree Inorder Traversal

Problem Description:
Given the root of a binary tree, return the inorder traversal of its nodes' values.

Our Approach: (Inorder (Left -> Root -> Right))
- Traverse left subtree
- Visit the current node and push its value into std::vector
- Traverse right subtree

- Base Case :  root == nullptr (No node exists) -> return

Time Complexity: O(n)
Space Complexity: O(h) - (where h is the height of the tree)
*/

class Solution {
public:
    void inorder(TreeNode* root, std::vector<int>& result) {
        if (root == nullptr)
            return;
        inorder(root->left, result);
        result.push_back(root->val);
        inorder(root->right, result);
    }

    std::vector<int> inorderTraversal(TreeNode* root) {
        // inorder => left root right
        std::vector<int> result;
        inorder(root, result);
        return result;
    }
};