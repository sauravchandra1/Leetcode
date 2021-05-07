class Solution {
public:
    bool isBipartite(vector<vector<int>>& graph) {
        int V = graph.size();
        if (V == 0) return true;
        vector<int> color(V, -1);
        function<void(int, int)> dfs = [&](int source, int c) {
            color[source] = c;
            for (int i = 0; i < graph[source].size(); i++) {
                int node = graph[source][i];
                if (color[node] == -1) {
                    dfs(node, 1 - c);
                } 
            }
        };
        bool ok = true;
        for (int i = 0; i < V; i++) {
            if (color[i] == -1) dfs(i, 0);
        }
        for (int i = 0; i < V; i++) {
            int c = 1 - color[i];
            for (auto v : graph[i]) {
                if (color[v] != c) return false;
            }
        }
        return true;
    }
};