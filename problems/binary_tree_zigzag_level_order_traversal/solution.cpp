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
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        const int N = 1e5;
        vector<vector<int>> order(N);
        int level = 0;
        function<void(TreeNode*, int)> dfs = [&](TreeNode* curr, int l) {
            if (curr == nullptr) return;
            order[l].push_back(curr->val);
            dfs(curr->left, l + 1);
            dfs(curr->right, l + 1);
            level = max(level, l + 1);
        };
        dfs(root, 0);
        order.resize(level);
        for (int i = 1; i < level; i += 2) reverse(order[i].begin(), order[i].end());
        return order;
    }
};