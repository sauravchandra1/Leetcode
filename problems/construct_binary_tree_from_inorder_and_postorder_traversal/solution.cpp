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
    map<int, int> mp;
    int idx;
    TreeNode* trav(vector<int>& inorder, vector<int>& postorder, int l, int r) {
        TreeNode* root = new TreeNode();
        if (l > r) return NULL;
        if (idx < 0) return NULL;
        root->val = postorder[idx];
        if (l == r) {
            idx--;
            return root;
        } else {
            int i = mp[postorder[idx]];
            idx--;
            root->right = trav(inorder, postorder, i + 1, r);
            root->left = trav(inorder, postorder, l, i - 1);
            return root;
        }
    }
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        for (int i = 0; i < inorder.size(); i++) {
            mp[inorder[i]] = i;
        }
        int len = inorder.size() - 1;
        idx = len;
        TreeNode* root = trav(inorder, postorder, 0, len);
        return root;
    }
};