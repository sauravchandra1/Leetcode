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
        unordered_map<int, int> idx;
        for (int i = 0; i < inorder.size(); i++) idx[inorder[i]] = i;
        int root = inorder.size() - 1;
        function<TreeNode*(int, int)> dfs = [&](int l, int r) {
            TreeNode* node = NULL;
            if (l > r) return node;
            int p = idx[postorder[root]];
            node = new TreeNode(inorder[p]);
            root--;
            if (l == r) return node;
            node->right = dfs(p + 1, r);
            node->left = dfs(l, p - 1);
            return node;
        };
        return dfs(0, inorder.size() - 1);
    }
};