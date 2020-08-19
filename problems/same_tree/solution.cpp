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
    bool isSameTree(TreeNode* p, TreeNode* q) {
        function<bool(TreeNode*, TreeNode*)> dfs = [&](TreeNode* p, TreeNode* q) {
            if (p == NULL && q != NULL) return false;
            if (p != NULL && q == NULL) return false;
            if (p == NULL && q == NULL) return true;
            if (p->val != q->val) return false;
            int l = dfs(p->left, q->left);
            int r = dfs(p->right, q->right);
            return (l && r);
        };
        return dfs(p, q);
    }
};