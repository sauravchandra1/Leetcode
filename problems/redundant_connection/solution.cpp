class Solution {
public:
    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        int n = edges.size();
        vector<vector<int>> tree(n);
        vector<bool> color(n);
        int count = 0;
        for (auto& e : edges) {
            tree[e[0] - 1].push_back(e[1] - 1);
            tree[e[1] - 1].push_back(e[0] - 1);
        }
        int u, v;
        function<void(int, int)> dfs = [&](int source, int par) {
            color[source] = true;
            count++;
            for (auto& node : tree[source]) {
                if ((source == u && node == v) || (source == v && node == u)) continue;
                if (node == par) continue;
                if (!color[node]) dfs(node, source);
            }
        };
        for (int i = n - 1; i >= 0; i--) {
            color.assign(n, false);
            count = 0;
            u = edges[i][0] - 1;
            v = edges[i][1] - 1;
            dfs(0, -1);
            if (count == n) return edges[i];
        }
        return {0, 0};
    }
};