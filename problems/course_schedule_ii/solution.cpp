class Solution {
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        vector<vector<int>> tree(numCourses);
        for (auto& v : prerequisites) 
            tree[v[0]].push_back(v[1]);
        vector<int> color(numCourses), ans;
        bool isFine = true;
        function<void(int)> dfs = [&](int source) {
            if (color[source] == 2) return;
            else if (color[source] == 1) {
                isFine = false;
                return;
            }
            color[source] = 1;
            for (auto& node : tree[source]) {
                if (!isFine) return;
                if (color[node] != 2) dfs(node);
            }
            ans.push_back(source);
            color[source] = 2;
        };
        for (int i = 0; i < numCourses; i++) {
            dfs(i);
            if (!isFine) return {};
        }
        return ans;
    }
};