class Solution {
public:
    int mincostTickets(vector<int>& days, vector<int>& costs) {
        const int inf = 1e8;
        sort(days.begin(), days.end());
        int n = days.size();
        vector<int> dp(n, -1);
        auto go = [&](int i) {
            int pos = upper_bound(days.begin(), days.end(), i) - days.begin();
            return pos;
        };
        function<int(int)> dfs = [&](int idx) {
            if (idx == n) return 0;
            int &res = dp[idx];
            if (res != -1) return res;
            res = inf;
            int a = dfs(idx + 1) + costs[0];
            int b = dfs(go(days[idx] + 6)) + costs[1];
            int c = dfs(go(days[idx] + 29)) + costs[2];
            res = min(a, b);
            res = min(res, c);
            return res;
        };
        return dfs(0);
    }
};
