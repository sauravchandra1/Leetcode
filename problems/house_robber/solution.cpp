class Solution {
public:
    int rob(vector<int>& nums) {
        int len = nums.size();
        vector<int> dp(len, -1);
        function<int(int)> dfs = [&](int idx) {
            if (idx >= len) return 0;
            if (idx == len - 1) return nums[idx];
            auto& res = dp[idx];
            if (res != -1) return res;
            res = 0;
            res = max(res, dfs(idx + 2));
            res = max(res, dfs(idx + 3));
            res += nums[idx];
            return res;
        };
        int ans = 0;
        ans = max(ans, dfs(0));
        ans = max(ans, dfs(1));
        return ans;
    }
};