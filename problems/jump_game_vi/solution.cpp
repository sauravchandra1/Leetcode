class Solution {
public:
    const int inf = 1e9;
    int maxResult(vector<int>& nums, int k) {
        int len = nums.size();
        vector<int> dp(len, -1), _max(len);
        priority_queue<pair<int, int>> pq;
        function<void(int)> dfs = [&](int idx) {
            if (idx == len - 1) {
                dp[idx] = nums[idx];
                pq.push({nums[idx], idx});
                return;
            }
            auto& res = dp[idx];
            if (res != -1) return;
            dfs(idx + 1);
            while (!pq.empty() && pq.top().second > idx + k) pq.pop();
            res = nums[idx] + pq.top().first;
            pq.push({res, idx});
        };
        dfs(0);
        return dp[0];
    }
};