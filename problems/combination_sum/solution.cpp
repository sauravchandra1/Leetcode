class Solution {
public:
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>> ans;
        int n = candidates.size();
        if (n == 0) {
            return ans;
        }
        vector<int> res;
        sort(candidates.begin(), candidates.end());
        function<void(int, int)> dfs = [&](int idx, int target) {
            if (target == 0) {
                ans.push_back(res);
                return ;
            }
            if (idx == n) return ;
            for (int i = idx; i < n; i++) {
                if (candidates[i] > target) {
                    break;
                }
                res.push_back(candidates[i]);
                dfs(i, target - candidates[i]);
                res.pop_back();
            }
        };
        dfs(0, target);
        return ans;
    }
};