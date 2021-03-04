class Solution {
public:
    int max(int a, int b) {
        return (a > b ? a : b);
    }
    int min(int a, int b) {
        return (a < b ? a : b);
    }
    int max(int a, int b, int c) {
        return max(max(a, b), max(b, c));
    }
    int min(int a, int b, int c) {
        return min(min(a, b), min(b, c));
    }
    int maxProduct(vector<int>& nums) {
        int n = nums.size();
        if (n == 0) return 0;
        vector<pair<int, int>> dp(n + 1, make_pair(INT_MIN, INT_MAX));
        int ans = nums[0];
        function<pair<int, int>(int)> recur = [&](int idx) {
            if (idx == n - 1) {
                ans = max(ans, nums[idx]);
                return make_pair(nums[idx], nums[idx]);
            }
            auto& res = dp[idx];
            if (res.first != INT_MIN) return res;
            int v = nums[idx];
            res.first = res.second = v;
            res.first = 
                max(v, recur(idx + 1).first * v, recur(idx + 1).second * v);
            res.second = 
                min(v, recur(idx + 1).first * v, recur(idx + 1).second * v);
            ans = max(ans, res.first);
            return res;
            
        };
        recur(0);
        return ans;
    }
};