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
    int ans = 0;
    int sumRootToLeaf(TreeNode* root, int num = 0) {
        if (root == 0) return 0;
        sumRootToLeaf(root->left, (num << 1) + root->val);
        sumRootToLeaf(root->right, (num << 1) + root->val);
        if (!root->left && !root->right) ans += (num << 1) + root->val;
        return ans;
    }
};