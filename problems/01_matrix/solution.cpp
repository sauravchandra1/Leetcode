class Solution {
    public:
            vector < vector < int >> updateMatrix(vector < vector < int >> & matrix) {
            int n, m;
            n = matrix.size(), m = matrix[0].size();
            vector < vector < int >> dp = vector < vector < int >> (n, vector < int > (m, n * m + 1));
            int a[4] = {
                -1,
                0,
                0,
                1
            }, b[4] = {
                0,
                1,
                -1,
                0
            };
            list < pair < int, int >> q;
            for (int i = 0; i < n; ++i) {
                for (int j = 0; j < m; ++j) {
                    if (matrix[i][j] == 0) {
                        q.push_back({
                            i,
                            j
                        });
                        dp[i][j] = 0;
                    }
                }
            }
            for (int lev = 1; true; lev++) {
                if (q.empty()) {
                    return dp;
                }
                int qn = q.size(), curi, curj;
                pair < int, int > cur;
                while (qn--) {
                    cur = q.front();
                    q.pop_front();
                    curi = cur.first, curj = cur.second;
                    for (int i = 0; i < 4; i++) {
                        int ii = curi + a[i], jj = curj + b[i];
                        if (ii < 0 || ii >= n || jj < 0 || jj >= m) continue;
                        if (dp[ii][jj] > lev) {
                            dp[ii][jj] = lev;
                            q.push_back({
                                ii,
                                jj
                            });
                        }
                    }
                }
            }
            return dp;
        }
};