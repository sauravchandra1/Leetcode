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
    TreeNode* sortedArrayToBST(vector<int>& nums) {
        function<TreeNode*(int, int)> dfs = [&](int l, int r) {
            TreeNode* root = 0;
            if (l == r) root = new TreeNode(nums[l]);
            if (l >= r) return root;
            int m = (l + r) / 2;
            root = new TreeNode(nums[m]);
            root->left = dfs(l, m - 1);
            root->right = dfs(m + 1, r);
            return root;
        };
        return dfs(0, nums.size() - 1);
    }
};