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
    vector<TreeNode*> generateTrees(int n) {
        function<vector<TreeNode*>(int, int)> dfs = [&](int l, int r) {
            vector<TreeNode*> ans;
            if (l > r) {
                ans.push_back(0);
                return ans;
            }
            if (l == r) {
                ans.push_back(new TreeNode(l));
                return ans;
            }
            for (int i = l; i <= r; i++) {
                vector<TreeNode*> left = dfs(l, i - 1);
                vector<TreeNode*> right = dfs(i + 1, r);
                for (auto L : left) {
                    for (auto R : right) {
                        TreeNode* curr = new TreeNode(i);
                        curr->left = L;
                        curr->right = R;
                        ans.push_back(curr);
                    }
                }
            }
            return ans;
        };
        return dfs(1, n);
    }
};