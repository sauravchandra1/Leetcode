class Solution {
public:
    const int inf = 1e9;
    int minRefuelStops(int target, int startFuel, vector<vector<int>>& stations) {
        int len = stations.size();
        vector<vector<int>> dp(len + 1, vector<int> (len + 1, -1));
        function<int(int, int)> dfs = [&](int idx, int use) {
            if (use > idx) return 0;
            if (idx == 0 || use == 0) return startFuel;   
            auto& res = dp[idx][use];
            if (res != -1) return res;
            res = 0;
            int last = dfs(idx - 1, use - 1);
            if (last >= stations[idx - 1][0]) 
                res = last + stations[idx - 1][1];
            res = max(res, dfs(idx - 1, use));
            return res;
        };
        for (int i = 0; i <= len; i++) 
            if (dfs(len, i) >= target) return i;
        return -1;
    }
};