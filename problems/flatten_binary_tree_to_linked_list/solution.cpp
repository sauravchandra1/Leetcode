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
    void flatten(TreeNode* root) {
        function<TreeNode*(TreeNode*)> dfs = [&](TreeNode* root) {
            if (root == 0) return root;
            TreeNode* left = dfs(root->left);
            TreeNode* right = dfs(root->right);
            if (left) while (left->right) left = left->right;
            if (left) left->right = right;
            else root->left = right;
            root->right = root->left;
            root->left = 0;
            return root;
        };
        dfs(root);
    }
};