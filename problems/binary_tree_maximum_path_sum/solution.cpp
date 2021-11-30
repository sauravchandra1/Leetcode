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
    int maxPathSum(TreeNode* root) {
        int ans = 0, _max = -1e9;
        function<int(TreeNode*)> dfs = [&](TreeNode* root) {
            if (root == 0) return 0;
            int a = dfs(root->left);
            int b = dfs(root->right);
            _max = max(_max, root->val);
            ans = max(ans, max(0, a + root->val + b));
            return max(0, max(a, b) + root->val);
        };
        dfs(root);
        if (_max < 0) return _max;
        return ans;
    }
};