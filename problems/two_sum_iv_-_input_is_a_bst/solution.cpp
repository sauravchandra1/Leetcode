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
    bool findTarget(TreeNode* root, int k) {
        unordered_set<int> se;
        bool ok = false;
        function<void(TreeNode*)> dfs = [&](TreeNode* root) {
            if (!root || ok) return;
            dfs(root->left);
            if (se.count(k - root->val)) ok = true;
            se.insert(root->val);
            dfs(root->right);
        };
        dfs(root);
        return ok;
    }
};