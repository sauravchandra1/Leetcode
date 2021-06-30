/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        TreeNode* ans = 0;
        function<int(TreeNode*)> dfs = [&](TreeNode* curr) {
            if (ans != 0 || !curr) return 0;
            int res = dfs(curr->left) + dfs(curr->right);
            if (curr == p || curr == q) res++;
            if (res == 2 && !ans) ans = curr;
            return res;
        };
        dfs(root);
        return ans;
    }
};