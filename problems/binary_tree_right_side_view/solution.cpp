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
    vector<int> rightSideView(TreeNode* root) {
        vector<int> ans;
        function<void(TreeNode*, int)> dfs = [&](TreeNode* root, int d) {
            if (root == NULL) return ;
            if (d > ans.size()) {
                ans.push_back(root->val);
            }
            dfs(root->right, d + 1);
            dfs(root->left, d + 1);
        };
        dfs(root, 1);
        return ans;
    }
};