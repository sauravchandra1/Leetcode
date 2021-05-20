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
        queue<pair<TreeNode*, int>> Q;
        vector<vector<int>> ans;
        vector<int> vec;
        if (root == 0) return ans;
        int max_depth = 0;
        Q.push({root, 0});
        while (!Q.empty()) {
            TreeNode* root = Q.front().first;
            int d = Q.front().second;
            if (d > max_depth) {
                ans.push_back(vec);
                vec.clear();
                max_depth = d;
            }
            vec.push_back(root->val);
            Q.pop();
            if (root->left) Q.push({root->left, d + 1});
            if (root->right) Q.push({root->right, d + 1});
        }
        if (vec.size() > 0) ans.push_back(vec);
        return ans;
    }
};