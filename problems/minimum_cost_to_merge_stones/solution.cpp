class Solution {
public:
    int mergeStones(vector<int>& stones, int K) {
        int n = stones.size();
        vector<int> pre(n + 1, 0);
        const int inf = 1e5;
        for (int i = 1; i < n + 1; i++) pre[i] += (pre[i - 1] + stones[i - 1]);
        vector<vector<int>> dp(n + 1, vector<int> (n + 1, -1));
        function<int(int, int)> dfs = [&](int l, int r) {
            int &res = dp[l][r];
            if (res != -1) return res;
            int len = r - l + 1;
            if (len < K) return (res = 0);
            res = inf;
            for (int i = l; i < r; i += K - 1) 
                res = min(res, dfs(l, i) + dfs(i + 1, r));
            if (res >= inf) res = 0;
            if ((len - K) % (K - 1) == 0) res += (pre[r + 1] - pre[l]);
            return res;
        };
        return (((n - K) % (K - 1) == 0) ? dfs(0, n - 1) : -1);
    }
};