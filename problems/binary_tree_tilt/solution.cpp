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
    int ans;
public:
    Solution() { ans = 0; }
    int findTilt(TreeNode* root) {
        function<int(TreeNode*)> dfs = [&](TreeNode* root) {
            if (root == 0) return 0;
            int t = root->val;
            int l = dfs(root->left), r = dfs(root->right);
            ans += abs(l - r);
            return (l + r + t);
        };
        dfs(root);
        return ans;
    }
};