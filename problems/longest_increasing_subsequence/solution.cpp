class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        int len = nums.size();
        vector<int> dp(len, -1);
        function<int(int)> dfs = [&](int idx) {
            if (idx == len - 1) return 1;
            auto& res = dp[idx];
            if (res != -1) return res;
            res = 1;
            for (int i = idx + 1; i < len; i++) 
                if (nums[i] > nums[idx]) 
                    res = max(res, dfs(i) + 1);
            return res;
        };
        int ans = 0;
        for (int i = 0; i < len; i++) ans = max(ans, dfs(i));
        return ans;
    }
};