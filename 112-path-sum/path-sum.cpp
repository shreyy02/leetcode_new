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
    bool hasPathSum(TreeNode* root, int targetSum) {
        return fun(root, 0, targetSum);
    }

    bool fun(TreeNode* root, int sum, int targetSum) {
        
        if (root == NULL)
            return false;

        sum += root->val;

        // Leaf node
        if (root->left == NULL && root->right == NULL) {
            if (sum == targetSum)
                return true;

            return false;
        }

        return fun(root->left, sum, targetSum) ||
               fun(root->right, sum, targetSum);
    }
};