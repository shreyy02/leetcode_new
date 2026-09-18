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
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        
        if (preorder.empty() || inorder.empty())
            return NULL;

        // First element of preorder is root
        TreeNode* root = new TreeNode(preorder[0]);

        // Find root in inorder
        int index = 0;

        while (inorder[index] != preorder[0]) {
            index++;
        }

        // Left subtree
        vector<int> leftInorder(inorder.begin(), inorder.begin() + index);
        vector<int> leftPreorder(preorder.begin() + 1,
                                 preorder.begin() + 1 + index);

        // Right subtree
        vector<int> rightInorder(inorder.begin() + index + 1,
                                  inorder.end());
        vector<int> rightPreorder(preorder.begin() + 1 + index,
                                  preorder.end());

        root->left = buildTree(leftPreorder, leftInorder);
        root->right = buildTree(rightPreorder, rightInorder);

        return root;
    }
};