/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    vector<int> ans;

    vector<int> inorderTraversal(TreeNode* root) {
        fun(root);
        return ans;
    }

    void fun(TreeNode* root) {
        if (root == nullptr)
            return;

        fun(root->left);          // Left
        ans.push_back(root->val); // Root
        fun(root->right);         // Right
    }
};