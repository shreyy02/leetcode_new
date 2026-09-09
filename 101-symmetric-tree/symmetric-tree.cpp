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

    bool mirror(TreeNode* left, TreeNode* right) {

        // Both are NULL
        if (left == NULL && right == NULL)
            return true;

        // One is NULL
        if (left == NULL || right == NULL)
            return false;

        // Values are different
        if (left->val != right->val)
            return false;

        // Compare opposite sides
        return mirror(left->left, right->right) &&
               mirror(left->right, right->left);
    }

    bool isSymmetric(TreeNode* root) {

        if (root == NULL)
            return true;

        return mirror(root->left, root->right);
    }
};