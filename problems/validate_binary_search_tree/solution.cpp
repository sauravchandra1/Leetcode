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
    bool isValidBST(TreeNode* root) {
        vector<int> ans;
        bool ok = true;
        function<void(TreeNode*)> dfs = [&](TreeNode* root) {
            if (root == NULL) return;
            dfs(root->left);
            ans.push_back(root->val);
            dfs(root->right);
        };
        dfs(root);
        unordered_set<int> se(ans.begin(), ans.end());
        if (se.size() != ans.size()) ok = false;
        if (is_sorted(ans.begin(), ans.end()) && ok) return true;
        else return false;
    }
};