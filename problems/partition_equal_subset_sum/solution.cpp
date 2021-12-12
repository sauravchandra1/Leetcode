class Solution {
public:
    bool canPartition(vector<int>& nums) {
        int len = nums.size();
        int sum = accumulate(nums.begin(), nums.end(), 0);
        if (sum & 1) return false;
        vector<vector<int>> dp(len, vector<int>(2e4, -1));
        function<int(int, int)> dfs = [&](int idx, int target) {
            if (target == 0) return 1;
            if (idx == len || target < 0) return 0;
            auto& res = dp[idx][target];
            if (res != -1) return res;
            res = dfs(idx + 1, target - nums[idx]) || dfs(idx + 1, target);
            return res;
        };
        return dfs(0, sum / 2);
    }
};