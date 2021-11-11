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
    int findBottomLeftValue(TreeNode* root, int x = 0) {
        if (root == 0) return 0;
        findBottomLeftValue(root->left, x + 1);
        findBottomLeftValue(root->right, x + 1);
        if (mp.count(x) == 0) mp[x] = root->val;
        return (*mp.rbegin()).second;
    }
};