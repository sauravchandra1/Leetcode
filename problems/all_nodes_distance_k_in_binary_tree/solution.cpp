/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    vector<int> distanceK(TreeNode* root, TreeNode* target, int K) {
        vector<pair<int, int>> edge;
        function<int(TreeNode*)> dfs = [&](TreeNode* root) {
            if (root == NULL) return 0;
            int l = dfs(root->left);
            int r = dfs(root->right);
            if (root->left != NULL) {
                edge.push_back({root->val, root->left->val});
            }
            if (root->right != NULL) {
                edge.push_back({root->val, root->right->val});
            }
            return (l + r + 1);
        };
        int n = dfs(root);
        vector<int> ans;
        if (n <= 1) return ans;
        vector<vector<int>> tree(n);
        for (auto v : edge) {
            tree[v.first].push_back(v.second);
            tree[v.second].push_back(v.first);
        }
        queue<int> Q;
        int d = 0;
        Q.push(target->val);
        vector<int> seen(n, false);
        seen[target->val] = true;
        while (!Q.empty()) {
            int len = Q.size();
            if (d == K) {
                while (!Q.empty()) {
                    ans.push_back(Q.front());
                    Q.pop();
                }
                break;
            }
            d++;
            for (int i = 0; i < len; i++) {
                int node = Q.front();
                Q.pop();
                for (auto v : tree[node]) {
                    if (seen[v] == false) {
                        seen[v] = true;
                        Q.push(v);
                    }
                }
            }
        }
        return ans;
    }
};