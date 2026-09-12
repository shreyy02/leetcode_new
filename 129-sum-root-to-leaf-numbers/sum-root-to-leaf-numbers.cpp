class Solution {
public:
    int sumNumbers(TreeNode* root) {
        return fun(root, 0);
    }

    int fun(TreeNode* root, int sum) {
        if (root == NULL)
            return 0;

        // Build the number
        sum = sum * 10 + root->val;

        // Leaf node
        if (root->left == NULL && root->right == NULL)
            return sum;

        return fun(root->left, sum) +
               fun(root->right, sum);
    }
};