class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        int len = nums.size();
        sort(nums.begin(), nums.end());
        unordered_map<int, int> mp;
        for (int i = 0; i < len; i++) mp[nums[i]] = i;
        int val;
        vector<vector<int>> ans;
        for (int i = 0; i < len; i++) {
            for (int j = i + 1; j < len; j++) {
                for (int k = j + 1; k < len; k++) {
                    val = target - (nums[i] + nums[j] + nums[k]);
                    if (mp[val] > k) ans.push_back({nums[i], nums[j], nums[k], val});
                    while (k + 1 < len && nums[k + 1] == nums[k]) k++;
                }
                while (j + 1 < len && nums[j + 1] == nums[j]) j++;
            }
            while (i + 1 < len && nums[i + 1] == nums[i]) i++;
        }
        return ans;
    }
};