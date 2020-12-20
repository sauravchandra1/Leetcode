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
    bool ok = true;
    int trav(TreeNode* root) {
        if (root == NULL) return 0;
        int a = trav(root->left);
        int b = trav(root->right);
        if (abs(a - b) > 1) ok = false;
        return max(a, b) + 1;
    }
    bool isBalanced(TreeNode* root) {
        trav(root);
        return ok;
    }
};