class Solution {
public:
    int findLUSlength(vector<string>& strs) {
        int len = strs.size();
        sort(strs.begin(), strs.end(), [&](const string &a, const string &b) {
            return a.size() > b.size();
        });
        const int N = 11;
        vector<bool> seen(len, false);
        vector<vector<int>> dp(N, vector<int>(N));
        vector<vector<int>> res(len, vector<int>(len, -1));
        int i, j, ans;
        bool ok;
        
        function<int(int, int)> dfs = [&](int l1, int l2) {
            if (l1 < 0 || l2 < 0) return 0;
            auto& res = dp[l1][l2];
            if (res != -1) return res;
            if (strs[i][l1] == strs[j][l2])
                res = dfs(l1 - 1, l2 - 1) + 1;
            else 
                res = max(dfs(l1 - 1, l2), dfs(l1, l2 - 1));
            return res;
        };
        int _i, _j;
        for (i = 0; i < len; i++) {
            if (seen[i]) continue;
            ok = true;
            for (j = 0; j < len; j++) {
                if (i == j) continue;
                if (strs[j].size() < strs[i].size()) break;
                _i = min(i, j), _j = max(i, j);
                if (res[_i][_j] != -1) ans = res[_i][_j];
                else if (strs[i].size() == strs[j].size()) {
                    ans = (strs[i] == strs[j] ? strs[i].size() : 0);
                    res[_i][_j] = ans;
                }
                else {
                    dp.assign(N, vector<int>(N, -1));
                    ans = dfs(strs[i].size() - 1, strs[j].size() - 1);
                    res[_i][_j] = ans;
                }
                if (ans == strs[i].size()) {
                    seen[j] = seen[i] = true;
                    ok = false;
                    break;
                } 
            }
            if (ok) return strs[i].size();
        }
        return -1;
    }
};