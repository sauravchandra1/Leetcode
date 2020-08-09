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
    bool isSubtree(TreeNode* s, TreeNode* t) {
        TreeNode* s_head = s;
        TreeNode* t_head = t;
        if (t == NULL || s == NULL) return true;
        function<bool(TreeNode*, TreeNode*)> dfs = 
            [&](TreeNode* s_curr, TreeNode* t_curr) {
            if (s_curr == NULL && t_curr == NULL) return true;
            if (s_curr == NULL) return false;
            if (t_curr == NULL) return false;
            if (s_curr->val != t_curr->val) return false;
            bool l = dfs(s_curr->left, t_curr->left);
            bool r = dfs(s_curr->right, t_curr->right);
            return (l && r);
        };
        function<bool(TreeNode*)> dfs2 = [&](TreeNode* s_curr) {
            if (s_curr == NULL) return false;
            bool res = false;
            if (s_curr->val == t->val) res = dfs(s_curr, t);
            if (res) return true;
            bool l = dfs2(s_curr->left);
            bool r = dfs2(s_curr->right);
            return (l || r);
        };
        return dfs2(s);
    }
};