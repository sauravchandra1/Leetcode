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
    vector<vector<int>> verticalTraversal(TreeNode* root) {
        map<int, vector<pair<int, int>>> mp;
        function<void(TreeNode*)> dfs = [&](TreeNode* curr) {
            queue<pair<TreeNode*, pair<int, int>>> Q;
            Q.push(make_pair(curr, make_pair(0, 0)));
            pair<TreeNode*, pair<int, int>> pp;
            while (!Q.empty()) {
                pp = Q.front();
                Q.pop();
                if (pp.first == NULL) continue;
                mp[pp.second.first].push_back({pp.second.second, pp.first->val});
                Q.push(make_pair(pp.first->left, make_pair(pp.second.first - 1, pp.second.second + 1)));
                Q.push(make_pair(pp.first->right, make_pair(pp.second.first + 1, pp.second.second + 1)));
            }
        };
        dfs(root);
        vector<vector<int>> ans;
        for (auto v : mp) {
            sort(v.second.begin(), v.second.end(), [](const pair<int, int> &a, const pair<int, int> &b) {
                if (a.first == b.first) return (a.second < b.second);
                else return (a.first < b.first);
            });
            vector<int> res;
            for (auto r : v.second) res.push_back(r.second);
            ans.push_back(res);
        }
        return ans;
    }
};