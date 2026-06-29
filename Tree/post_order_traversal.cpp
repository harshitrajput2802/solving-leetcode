/*
Problem: 145. Binary Tree Postorder Traversal

Problem Description:
Given the root of a binary tree, return the postorder traversal of its nodes' values.

Our Approach: (Post-order (Left -> Right -> Root))
- Traverse left subtree
- Traverse right subtree
- Visit the current node and push its value into std::vector

- Base Case :  root == nullptr (No node exists) -> return

Time Complexity: O(n)
Space Complexity: O(h) - (where h is the height of the tree)
*/

class Solution {
public:
    void postOrder(TreeNode* root, std::vector<int>& result) {
        if (root == nullptr)
            return;

        postOrder(root->left, result);
        postOrder(root->right, result);
        result.push_back(root->val);
    }

    vector<int> postorderTraversal(TreeNode* root) {
        std::vector<int> result;
        postOrder(root, result);
        return result;
    }
};