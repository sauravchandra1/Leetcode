class Solution {
public:
    vector<int> findOrder(int len, vector<vector<int>>& pre) {
        vector<vector<int>> vec(len);
        for (auto& v : pre) 
            vec[v[0]].push_back(v[1]);
        vector<int> col(len), ans;
        bool ok = false;
        function<void(int)> dfs = [&](int source) {
            if (col[source] == 2 || ok) return;
            if (col[source] == 1) {
                ok = true;
                return;
            }
            col[source] = 1;
            for (auto& node : vec[source]) {
                if (col[node] != 2) dfs(node);
            }
            col[source] = 2;
            ans.push_back(source);
        };
        for (int i = 0; i < len; i++) dfs(i);
        if (ok) return {};
        return ans;
    }
};