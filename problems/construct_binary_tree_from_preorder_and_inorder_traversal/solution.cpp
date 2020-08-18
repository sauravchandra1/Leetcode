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
        unordered_map<int, int> mp;
        int len = inorder.size();
        if (len == 0) return NULL;
        int i = 0;
        for (auto v : inorder) {
            mp[v] = i;
            i++;
        }
        int idx = 0;
        function<TreeNode*(int, int)> dfs = [&](int s, int e) {
            TreeNode* root = NULL;
            if (s > e) return root;
            int p = mp[preorder[idx++]];
            root = new TreeNode(inorder[p]);
            root->left = dfs(s, p - 1);
            root->right = dfs(p + 1, e);
            return root;
        };
        return dfs(0, len - 1);
    }
};