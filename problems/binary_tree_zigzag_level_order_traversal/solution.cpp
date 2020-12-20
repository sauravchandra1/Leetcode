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
    vector<vector<int>> vec;
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        queue<TreeNode*> Q;
        if (root) Q.push(root);
        vector<int> tt;
        while (!Q.empty()) {
            int n = Q.size(); 
            tt.clear();
            for (int i = 0; i < n; i++) {
                auto p = Q.front();
                Q.pop();
                tt.push_back(p->val);
                if (p->left) Q.push(p->left);
                if (p->right) Q.push(p->right);
            }
            vec.push_back(tt);
        }
        for (int i = 1; i < vec.size(); i += 2) reverse(vec[i].begin(), vec[i].end());
        return vec;
    };
};