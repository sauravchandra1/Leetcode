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
    bool trav(TreeNode* p, TreeNode* q) {
        if (p == NULL && q == NULL) return true;
        if (p == NULL && q != NULL) return false;
        if (p != NULL && q == NULL) return false;
        if (p->val != q->val) return false;
        bool a = trav(p->left, q->right);
        bool b = trav(p->right, q->left);
        if (a && b) return true;
        else return false;
    }
    bool isSymmetric(TreeNode* root) {
        if (root == NULL) return true;
        return trav(root->left, root->right);
    }
};