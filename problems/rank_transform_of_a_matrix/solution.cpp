class Solution {
public:
    vector<vector<int>> matrixRankTransform(vector<vector<int>>& matrix) {
        int n = matrix.size();
        int m = matrix[0].size();
        map<int, vector<pair<int, int>>> mp;
        vector<vector<int>> ans(n, vector<int>(m));
        for (int i = 0; i < n; i++) 
            for (int j = 0; j < m; j++)
                mp[matrix[i][j]].push_back({i, j});
        vector<int> rank(n + m), parent(n + m);
        function<int(int)> find = [&](int x) {
            if (x != parent[x]) 
                parent[x] = find(parent[x]);
            return parent[x];
        };
        for (auto& vec : mp) {
            iota(parent.begin(), parent.end(), 0);
            for (auto& it : vec.second) {
                int i = it.first, j = it.second;
                int x = find(i), y = find(j + n);
                parent[x] = y;
                rank[y] = max(rank[x], rank[y]);
            }
            vector<int> curr(rank.begin(), rank.end());
            for (auto& it : vec.second) {
                int i = it.first, j = it.second;
                int r = find(i);
                ans[i][j] = rank[r] + 1;
                curr[i] = rank[r] + 1;
                curr[j + n] = rank[r] + 1;
            }
            for (int i = 0; i < n + m; i++) rank[i] = curr[i];
        }
        return ans;
    }
};