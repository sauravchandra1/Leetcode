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
    int maxAncestorDiff(TreeNode* root) {
        if (root == 0) return 0;
        int ans = 0;
        function<void(TreeNode*, int, int)> dfs = [&](TreeNode* root, int _max, int _min) {
            if (root == 0) return;
            dfs(root->left, max(_max, root->val), min(_min, root->val));
            dfs(root->right, max(_max, root->val), min(_min, root->val));
            ans = max(ans, max(_max - root->val, root->val - _min));
        };
        dfs(root, 0, 1e6);
        return ans;
    }
};