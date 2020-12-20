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
    vector<int> vec;
    int _min = -1;

    void trav(TreeNode* root, int curr = 0) {
        if (root == NULL) return ;
        if (curr > _min) {
            _min = curr;
            vec.push_back(root->val);
        }
        trav(root->right, curr + 1);
        trav(root->left, curr + 1);
    }
    vector<int> rightSideView(TreeNode* root) {
        trav(root);
        return vec;
    }
};