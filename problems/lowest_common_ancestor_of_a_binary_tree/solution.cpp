/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    TreeNode* lca = NULL;
    bool trav(TreeNode* root, TreeNode* p, TreeNode* q) {
        if (root == NULL) return false;
        if (root->val == p->val || root->val == q->val) {
            bool l = trav(root->left, p, q);
            bool r = trav(root->right, p, q);
            if (l || r) lca = root;
            return true;
        } 
        bool l = trav(root->left, p, q);
        bool r = trav(root->right, p, q);
        if (l && r) {
            lca = root;
            return true;
        } 
        if (l || r) return true;
        else return false;
    }
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        trav(root, p, q);
        return lca;
    }
};