class Solution {
public:
    vector<vector<int>> allPathsSourceTarget(vector<vector<int>>& graph) {
        vector<vector<int>> ans;
        vector<int> res;
        function<void(int)> dfs = [&](int source) {
            if (source == graph.size() - 1) {
                ans.push_back(res);
                return;
            }
            for (auto& node : graph[source]) {
                res.push_back(node);
                dfs(node);
                res.pop_back();
            }
        };
        res.push_back(0);
        dfs(0);
        return ans;
    }
};