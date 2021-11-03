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
    int sumNumbers(TreeNode* root, int curr = 0) {
        if (root == 0) return 0;
        if (root->left == 0 && root->right == 0) {
            sum += curr * 10 + root->val;
            return sum;
        }
        sumNumbers(root->left, curr * 10 + root->val);
        sumNumbers(root->right, curr * 10 + root->val);
        return sum;
    }
};