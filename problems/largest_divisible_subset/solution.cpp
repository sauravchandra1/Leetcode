class Solution {
public:
    vector<int> largestDivisibleSubset(vector<int>& nums) {
        int len = nums.size();
        vector<int> dp(len, -1);
        sort(nums.begin(), nums.end());
        function<int(int)> dfs = [&](int idx) {
            auto& res = dp[idx];
            if (res != -1) return res;
            res = 1;
            for (int i = idx + 1; i < len; i++) {
                if (nums[i] % nums[idx] == 0) 
                    res = max(res, dfs(i) + 1);
            }
            return res;
        };
        int ans = 0, l = 1;
        for (int i = 0; i < len; i++) ans = max(ans, dfs(i));
        vector<int> res;
        for (int i = 0; i < len; i++) {
            if (!ans) break;
            if (dp[i] == ans && (nums[i] % l == 0)) {
                ans--;
                res.push_back(nums[i]);
                l = nums[i];
            }
        }
        return res;
    }
};