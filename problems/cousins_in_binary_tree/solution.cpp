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
    bool isCousins(TreeNode* root, int x, int y) {
        int depth_x = 0, depth_y = 0;
        TreeNode* par_x = 0, *par_y = 0;
        function<void(TreeNode*, int, TreeNode*)> dfs = [&](TreeNode* root, int d, TreeNode* par) {
            if (root == 0) return;
            if (root->val == x) {
                depth_x = d;
                par_x = par;
            }
            if (root->val == y) {
                depth_y = d;
                par_y = par;
            }
            dfs(root->left, d + 1, root);
            dfs(root->right, d + 1, root);
        };
        dfs(root, 0, 0);
        if (depth_x == depth_y && par_x != par_y) return true;
        return false;
    }
};