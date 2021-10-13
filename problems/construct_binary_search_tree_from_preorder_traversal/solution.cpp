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
    TreeNode* bstFromPreorder(vector<int>& preorder) {
        int idx = 0;
        // order == true->left else right
        function<TreeNode*(int, int)> dfs = [&](int _min, int _max) {
            TreeNode* temp = 0;
            if (idx == preorder.size() || preorder[idx] < _min || preorder[idx] > _max) return temp;
            TreeNode* curr = new TreeNode(preorder[idx]);
            idx++;
            curr->left = dfs(min(_min, curr->val), min(_max, curr->val));
            curr->right = dfs(max(_min, curr->val), max(_max, curr->val));
            return curr;
        };
        return dfs(-1e9, 1e9);
    }
};