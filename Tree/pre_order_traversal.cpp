/*
Problem: 144. Binary Tree Preorder Traversal

Problem Description:
Given the root of a binary tree, return the preorder traversal of its nodes' values.

Our Approach: (Pre-order (Root -> Left -> Right))
- Visit the current node and push its value into std::vector
- Traverse left subtree
- Traverse right subtree

- Base Case :  root == nullptr (No node exists) -> return

Time Complexity: O(n)
Space Complexity: O(h) - (where h is the height of the tree)
*/

class Solution {
public:
    void preOrder(TreeNode* root, std::vector<int>& result) {
        if (root == nullptr)
            return;

        result.push_back(root->val);

        preOrder(root->left, result);
        preOrder(root->right, result);
    }

    vector<int> preorderTraversal(TreeNode* root) {
        std::vector<int> result;
        preOrder(root, result);
        return result;
    }
};