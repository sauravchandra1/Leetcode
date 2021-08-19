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
    int maxProduct(TreeNode* root) {
        const long long mod = 1e9 + 7;
        long long ans = 0, sum = 0, temp;
        bool ok = true;
        function<int(TreeNode*)> dfs = [&](TreeNode* root) {
            if (!root) return 0;
            if (ok) sum += root->val;
            int l = dfs(root->left);
            int r = dfs(root->right);
            temp = l + root->val + r;
            if (!ok) ans = max(ans, (temp * (sum - temp)));
            return (int)temp;
        };
        dfs(root);
        ok = false;
        dfs(root);
        return ans % mod;
    }
};