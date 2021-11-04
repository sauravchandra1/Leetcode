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
    int sum = 0;
    int sumOfLeftLeaves(TreeNode* root, int l = -1) {
        if (root == 0) return 0;
        if (root->left == 0 && root->right == 0 && l == 1) {
            sum += root->val;
            return 0;
        }
        sumOfLeftLeaves(root->left, 1);
        sumOfLeftLeaves(root->right, 0);
        return sum;
    }
};