class Solution {
public:
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        int len = candidates.size();
        vector<vector<int>> dp;
        if (len == 0 || target == 0) return dp;
        sort(candidates.begin(), candidates.end());
        vector<int> ans;
        function<void(int, int)> dfs = [&](int t, int idx) {
            if (t == 0) {
                dp.push_back(ans);
                return ;
            }
            if (idx == len) return ;
            for (int i = idx; i < len; i++) {
                if (candidates[i] > t) break;
                ans.push_back(candidates[i]);
                dfs(t - candidates[i], i);
                ans.pop_back();
            }
        };
        dfs(target, 0);
        return dp;
    }
};