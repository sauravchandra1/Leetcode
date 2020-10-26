class Solution {
public:
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        vector<vector<int>> ans;
        vector<int> vec;
        sort(candidates.begin(), candidates.end());
        int n = candidates.size();
        function<void(int, int)> dfs = [&](int idx, int sum) {
            if (sum == 0) {
                ans.push_back(vec);
                return ;
            }
            for (int i = idx; i < n; i++) {
                if (sum < candidates[i]) break;
                if (i > idx && candidates[i] == candidates[i - 1]) continue;
                vec.push_back(candidates[i]);
                dfs(i + 1, sum - candidates[i]);
                vec.pop_back();
            }
        };
        dfs(0, target);
        return ans;      
    }
};