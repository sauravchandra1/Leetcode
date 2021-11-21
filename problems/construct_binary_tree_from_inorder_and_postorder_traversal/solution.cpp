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
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        unordered_map<int, int> mp;
        int len = inorder.size();
        int idx = len - 1;
        for (int i = 0; i < len; i++) mp[inorder[i]] = i;
        function<TreeNode*(int, int)> dfs = [&](int l, int r) {
            TreeNode* curr = 0;
            if (idx < 0 || l > r) return curr;
            int i = mp[postorder[idx--]];
            curr = new TreeNode(inorder[i]);
            curr->right = dfs(i + 1, r);
            curr->left = dfs(l, i - 1);
            return curr;
        };
        return dfs(0, len - 1);
    }
};