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
    int countNodes(TreeNode* root) {
        if (!root) return 0;
        int h = 1;
        TreeNode* curr = root;
        while (curr->left) {
            curr = curr->left;
            h++;
        }
        int ans = (1 << h) - 1;
        bool ok = false;
        function<void(TreeNode*, int)> dfs = [&](TreeNode* root, int height) {
            if (ok) return;
            if (height == h) {
                if (!root) ans--;
                else ok = true;
                return;
            };
            dfs(root->right, height + 1);
            if (ok) return;
            dfs(root->left, height + 1);
        };
        dfs(root, 1);
        return ans;
    }
};