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
    int idx = 0;
    map<int ,int> mp;
    TreeNode* trav(vector<int>& preorder, vector<int>& inorder, int l, int r) {
        TreeNode* root = NULL;
        if (l > r || idx == inorder.size()) return NULL;
        if (l == r) {
            root = new TreeNode(preorder[idx]);
            idx++;
        }
        else {
            int i = mp[preorder[idx]];
            root = new TreeNode(preorder[idx]);
            idx++;
            root->left = trav(preorder, inorder, l, i - 1);
            root->right = trav(preorder, inorder, i + 1, r);
        }
        return root;
    }
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        for (int i = 0; i < inorder.size(); i++) {
            mp[inorder[i]] = i;
        }
        return trav(preorder, inorder, 0, inorder.size() - 1);
    }
};