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
    void flatten(TreeNode* root) {
        if (root == NULL) return;
        TreeNode* curr = NULL;
        stack<TreeNode*> stk;
        stk.push(root);
        while (!stk.empty()) {
            curr = stk.top();
            stk.pop();
            if (root != curr) {
                root->right = curr;
                root = curr;
            }
            if (curr->right) stk.push(curr->right);
            if (curr->left) stk.push(curr->left); 
            curr->left = NULL;
        }
    }
};