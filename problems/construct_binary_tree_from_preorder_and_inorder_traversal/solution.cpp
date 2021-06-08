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
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        int len = inorder.size();
        unordered_map<int, int> mp;
        for (int i = 0; i < len; i++) mp[inorder[i]] = i;
        int idx = 0;
        function<TreeNode*(int, int)> dfs = [&](int l, int r) {
            TreeNode* root = 0;
            if (l > r) return root;
            root = new TreeNode(preorder[idx++]);
            if (l == r) return root;
            int id = mp[preorder[idx - 1]];
            root->left = dfs(l, id - 1);
            root->right = dfs(id + 1, r);
            return root;
        };
        return dfs(0, len - 1);
    }
};