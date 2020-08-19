class Solution {
    public:
        int findCircleNum(vector < vector<int> > & M) {
            int n = M.size();
            int m = M[0].size();
            queue < pair < int, int >> q;
            vector < vector < bool >> vis(n, vector < bool > (m, false));
            int ans = 0;
            for (int i = 0; i < n; i++) {
                for (int j = 0; j < m; j++) {
                    if (M[i][j] == 1 && !vis[i][j]) {
                        vis[i][j] = true;
                        q.push({
                            i,
                            j
                        });
                        while (!q.empty()) {
                            int x = q.front().first;
                            int y = q.front().second;
                            q.pop();
                            for (int k = 0; k < m; k++) {
                                if (M[x][k] == 1 && !vis[x][k]) {
                                    vis[x][k] = true;
                                    q.push({
                                        x,
                                        k
                                    });
                                }
                            }

                            for (int k = 0; k < n; k++) {
                                if (M[k][y] == 1 && !vis[k][y]) {
                                    vis[k][y] == true;
                                    q.push({
                                        k,
                                        y
                                    });
                                }
                            }
                        }
                        ans++;
                    }
                }
            }
            return ans;
        }
}; 