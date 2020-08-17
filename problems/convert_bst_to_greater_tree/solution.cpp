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
    TreeNode* convertBST(TreeNode* root) {
        function<int(TreeNode*, int)> dfs = [&](TreeNode* root, int val) {
            if (root == NULL) return 0;
            int r = dfs(root->right, val);
            int v = root->val;
            root->val += r + val;
            int l = dfs(root->left, r + v + val);
            return (l + r + v);
        };
        dfs(root, 0);
        return root;
    }
};