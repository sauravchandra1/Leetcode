class Solution {
public:
    int maxSumSubmatrix(vector<vector<int>>& matrix, int k) {
        const int inf = 1e9;
        int n = matrix.size();
        int m = matrix[0].size();
        vector<vector<int>> vec(2, vector<int>(m + 1));
        int ans = -inf, _max;
        set<int> se;
        set<int> :: iterator it;
        int ok;
        for (int r = 0; r < n; r++) {
            ok = 0;
            for (int jj = 1; jj <= m; jj++) vec[ok][jj] = 0;
            for (int i = r + 1; i <= n; i++) {
                ok = 1 - ok;
                _max = 0;
                se.clear();
                se.insert(0);
                for (int j = 1; j <= m; j++) {
                    vec[ok][j] = vec[1 - ok][j] + matrix[i - 1][j - 1];
                    _max += vec[ok][j];
                    it = se.lower_bound(_max - k);
                    if (it != se.end())
                        ans = max(ans, _max - *it);
                    if (ans == k) return k;
                    se.insert(_max);
                }
            }
        }
        return ans;
    }
};