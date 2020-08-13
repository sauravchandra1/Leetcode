class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        const int N = numCourses;
        vector<vector<int>> tree(N);
        set<pair<int, int>> us;
        pair<int, int> p;
        for (auto v : prerequisites) {
            tree[v[0]].push_back(v[1]);
            p.first = v[1], p.second = v[0];
            if (v[0] == v[1]) return false;
            if (us.find(p) != us.end()) return false;
            p.first = v[0], p.second = v[1];
            us.insert(p);
        }
        vector<bool> seen(N, false), rr(N, false);
        bool ok = true;
        function<void(int, int)> dfs = [&](int source, int par) {
            seen[source] = true;
            rr[source] = true;
            if (!ok) false;
            for (auto node : tree[source]) {
                if (node == par) continue;
                if (seen[node] && rr[node]) {
                    ok = false;
                    return ;
                };
                if (!seen[node]) dfs(node, source);
            }
            rr[source] = false;
        };
        for (int i = 0; i < N; i++) if (!seen[i]) dfs(i, -1);
        return ok;
    }
};