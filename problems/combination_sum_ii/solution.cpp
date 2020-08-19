class Solution {
public:
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        int len = candidates.size();
        sort(candidates.begin(), candidates.end());
        vector<vector<int>> res;
        if (len == 0) {
            return res;
        }
        vector<int> tt;
        function<void(int, int)> dfs = [&](int idx, int target) {
            if (target == 0) {
                res.push_back(tt);
                return;
            }
            if (idx == len) return;
            for (int i = idx; i < len; i++) {
                if (i > idx && candidates[i] == candidates[i - 1]) continue;
                if (candidates[i] > target) {
                    break;
                }
                tt.push_back(candidates[i]);
                dfs(i + 1, target - candidates[i]);
                tt.pop_back();
            }
        };
        dfs(0, target);
        return res;
    }
};