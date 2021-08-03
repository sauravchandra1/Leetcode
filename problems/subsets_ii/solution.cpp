class Solution {
public:
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        set<vector<int>> ans;
        int n = nums.size();
        for (int i = 0; i < (1 << n); i++) {
            vector<int> vec;
            for (int j = 0; j < n; j++) {
                if (i & (1 << j)) vec.push_back(nums[j]);
            }
            ans.insert(vec);
        }
        vector<vector<int>> res(ans.begin(), ans.end());
        return res;
    }
};