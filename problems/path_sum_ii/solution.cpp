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
    vector<vector<int>> pathSum(TreeNode* root, int targetSum) {
        vector<vector<int>> ans;
        vector<int> vec;
        function<void(TreeNode*, int)> dfs = [&](TreeNode* root, int sum) {
            if (root == 0) return;
            int val = root->val;
            vec.push_back(val);
            if (root->left == 0 && root->right == 0) {
                if (sum + val == targetSum) ans.push_back(vec);
                vec.pop_back();
                return;
            }
            dfs(root->left, sum + val);
            dfs(root->right, sum + val);
            vec.pop_back();
        };
        dfs(root, 0);
        return ans;
    }
};