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
    TreeNode* pruneTree(TreeNode* root) {
        function<int(TreeNode*)> dfs = [&](TreeNode* root) {
            if (root == 0) return 0;
            int left = dfs(root->left);
            int right = dfs(root->right);
            if (left == 0) root->left = 0;
            if (right == 0) root->right = 0;
            return (left + right + root->val);
        };
        int ans = dfs(root);
        if (ans == 0) root = 0;
        return root;
    }
};