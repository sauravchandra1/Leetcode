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
        int _max = INT_MIN;
        int res = INT_MIN;
        function<int(TreeNode*)> dfs = [&](TreeNode* root) {
            if (root == NULL) return 0;
            int a = dfs(root->left);
            int b = dfs(root->right);
            _max = max(_max, a + b + root->val);
            res = max(res, root->val);
            return max(0, max(a, b) + root->val);
        };
        int ans = max(dfs(root), _max);
        if (ans == 0) return res;
        return ans;
    }
};