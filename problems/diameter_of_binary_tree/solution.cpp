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
    int trav(TreeNode* root) {
        if (root == NULL) return 0;
        int a = trav(root->left);
        int b = trav(root->right);
        ans = max(ans, a + b + 1);
        return max(a, b) + 1;
    }
    int diameterOfBinaryTree(TreeNode* root) {
        if (root == NULL) return 0;
        return max(ans, trav(root)) - 1;
    }
};