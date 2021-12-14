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
    int rangeSumBST(TreeNode* root, int low, int high) {
        if (root == 0) return 0;
        int l = 0, r = 0, ans = 0;
        if (root->val > low)
            l = rangeSumBST(root->left, min(low, root->val), min(high, root->val));
        if (root->val < high)
            r = rangeSumBST(root->right, max(low, root->val), max(high, root->val));
        if (root->val >= low && root->val <= high) ans = root->val;
        return (l + r + ans);
    }
};