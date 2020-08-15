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
        const int inf = 1e8;
        int ans = -inf;
        int res = -inf;
        function<int(TreeNode*)> dfs = [&](TreeNode* root) {
            if (root == NULL) return inf;
            int l = dfs(root->left);
            int r = dfs(root->right);
            int _min = min(l, r);
            if (_min == inf) return root->val;
            ans = max(ans, abs(root->val - _min));
            return min(root->val, _min);
        };
        function<int(TreeNode*)> dfs2 = [&](TreeNode* root) {
            if (root == NULL) return -inf;
            int l = dfs2(root->left);
            int r = dfs2(root->right);
            int _max = max(l, r);
            if (_max == -inf) return root->val;
            res = max(res, abs(root->val - _max));
            return max(_max, root->val);
        };
        dfs(root);
        dfs2(root);
        return max(ans, res);
    }
};