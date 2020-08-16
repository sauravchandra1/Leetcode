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
    int diameterOfBinaryTree(TreeNode* root) {
        int ans = 0;
        if (root == NULL) return ans;
        function<int(TreeNode*)> dfs = [&](TreeNode* root) {
            if (root == NULL) return 0;
            int a = dfs(root->left);
            int b = dfs(root->right);
            ans = max(ans, a + b);
            return max(a, b) + 1;
        };
        return max(ans, dfs(root->left) + dfs(root->right));
    }
};