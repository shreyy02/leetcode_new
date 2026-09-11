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
    bool findTarget(TreeNode* root, int k) {

        if (root == NULL)
            return false;

        stack<TreeNode*> st1, st2;

        TreeNode* left = root;
        TreeNode* right = root;

        // Initialize both stacks
        while (left != NULL) {
            st1.push(left);
            left = left->left;
        }

        while (right != NULL) {
            st2.push(right);
            right = right->right;
        }

        while (!st1.empty() && !st2.empty()) {

            TreeNode* l = st1.top();
            TreeNode* r = st2.top();

            // Same node cannot be used twice
            if (l == r)
                return false;

            int sum = l->val + r->val;

            if (sum == k)
                return true;

            if (sum < k) {
                // Move to next larger value
                st1.pop();

                TreeNode* temp = l->right;

                while (temp != NULL) {
                    st1.push(temp);
                    temp = temp->left;
                }
            }
            else {
                // Move to next smaller value
                st2.pop();

                TreeNode* temp = r->left;

                while (temp != NULL) {
                    st2.push(temp);
                    temp = temp->right;
                }
            }
        }

        return false;
    }
};