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
    int rob(TreeNode* root) {
        function<pair<int,int>(TreeNode*)> dfs = [&](TreeNode* root) {
            if (root == 0) return make_pair(0, 0);
            auto left = dfs(root->left);
            auto right = dfs(root->right);
            int t = left.second + right.second + root->val;
            int f = left.first + right.first;
            return make_pair(max(t, f), f);
        };
        auto p = dfs(root);
        return max(p.first, p.second);
    }
};