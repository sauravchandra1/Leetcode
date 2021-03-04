class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        int n = nums.size();
        if (n == 1) return n;
        vector<int> dp(n + 1, -1);
        function<int(int)> recur = [&](int idx) {
            if (idx == n - 1) {
                return 1;
            }
            auto& res = dp[idx];
            if (res != -1) return res;
            res = 0;
            for (int i = idx + 1; i < n; i++) {
                if (nums[i] > nums[idx]) res = max(res, recur(i));
            }
            res++;
            return res;
        };
        int ans = 0;
        for (int i = 0; i < n; i++) ans = max(ans, recur(i));
        // for (int i = 0; i < n; i++) cout << dp[i] << " ";
        return ans;
    }
};