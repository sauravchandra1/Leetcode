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
    int ans = -1e5;
    int _max = -1e5;
    int trav(TreeNode* root) {
        if (root == NULL) return 0;
        int a = trav(root->left);
        int b = trav(root->right);
        int m = max(0, max(a, b));
        _max = max(_max, root->val);
        ans = max(ans, max(0, root->val + max(0, a) + max(0, b)));
        return max(0, m + root->val);
    }
    int maxPathSum(TreeNode* root) {
        int res =  max(ans, trav(root));
        if (res == 0) return _max;
        else return res;
    }
};