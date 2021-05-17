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
    unordered_map<TreeNode*, int> mp;
    const int inf = 1e9;
    int minCameraCover(TreeNode* root) {
        function<int(TreeNode*)> dfs = [&](TreeNode* root) {
            if (root == 0) return 0;
            if (mp.find(root) != mp.end()) return mp[root];
            int a, b, c, d, e, f, g, h, i, j, k, l, m, n, o;
            a = b = c = d = e = f = g = h = i = j = k = l = m = n = o = 0;
            a = inf;
            if (root->left) {
                b = dfs(root->left);
                if (root->left->left) {
                    d = dfs(root->left->left);
                    h = dfs(root->left->left->left);
                    i = dfs(root->left->left->right);
                }
                if (root->left->right) {
                    e = dfs(root->left->right);
                    j = dfs(root->left->right->left);
                    k = dfs(root->left->right->right);
                }
            }
            if (root->right) {
                c = dfs(root->right);
                if (root->right->left) {
                    f = dfs(root->right->left);
                    l = dfs(root->right->left->left);
                    m = dfs(root->right->left->right);
                }
                if (root->right->right) {
                    g = dfs(root->right->right);
                    n = dfs(root->right->right->left);
                    o = dfs(root->right->right->right);
                }
            }
            a = min(a, b + c + 1);
            a = min(a, b + f + g + 1);
            a = min(a, d + e + c + 1);
            a = min(a, d + e + f + g + 1);
            
            int p = min(inf, c + d + e + 1);
            p = min(p, c + h + i + e + 1);
            p = min(p, c + d + j + k + 1);
            p = min(p, c + h + i + j + k + 1);
            
            int q = min(inf, b + f + g + 1);
            q = min(q, b + l + m + g + 1);
            q = min(q, b + f + n + o + 1);
            q = min(q, b + l + m + n + o + 1);
            // printf("%d %d %d %d %d %d %d %d %d %d %d %d %d %d %d \n", a, b, c, d, e, f, g, h, i, j, k, l, m, n, o);
            
            int ans = min(a, p);
            ans = min(ans, q);
            mp[root] = ans;
            return ans;
        };
        return dfs(root);
    }
};