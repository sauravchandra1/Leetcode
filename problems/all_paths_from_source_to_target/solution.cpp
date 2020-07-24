class Solution {
public:
    vector<vector<int>> allPathsSourceTarget(vector<vector<int>>& graph) {
        vector<vector<int>> ans;
        vector<int> vec;
        int n = graph.size() - 1;
        function<void(int)> dfs = [&](int source) {   
            if (source == n) {
                ans.push_back(vec);
                return ;
            }
            for (auto node : graph[source]) {
                vec.push_back(node);
                dfs(node);
                vec.pop_back();
            }
        };
        vec.push_back(0);
        dfs(0);
        return ans;
    }
};