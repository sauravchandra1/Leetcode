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
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>> ans;
        if (root == NULL) return ans;
        vector<int> res;
        queue<TreeNode*> Q;
        Q.push(root);
        while (!Q.empty()) {
            int len = Q.size();
            res.clear();
            for (int i = 0; i < len; i++) {
                auto root = Q.front();
                Q.pop();
                res.push_back(root->val);
                if (root->left != NULL) Q.push(root->left);
                if (root->right != NULL) Q.push(root->right);
            }
            ans.push_back(res);
        }
        return ans;
    }
};