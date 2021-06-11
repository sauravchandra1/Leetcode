class Solution {
public:
    int stoneGameVII(vector<int>& stones) {
        int len = stones.size();
        int sum = accumulate(stones.begin(), stones.end(), 0);
        vector<vector<int>> dp(len, vector<int> (len, -1));
        function<int(int, int, int)> dfs = [&](int l, int r, int sum) {
            if (l == r) return 0;
            auto& res = dp[l][r];
            if (res != -1) return res;
            res = max(sum - stones[l] - dfs(l + 1, r, sum - stones[l]), 
                      sum - stones[r] - dfs(l, r - 1, sum - stones[r]));
            return res;
        };
        return dfs(0, len - 1, sum);
    }
};