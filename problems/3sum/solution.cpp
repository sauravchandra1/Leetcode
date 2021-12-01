class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        int len = nums.size();
        sort(nums.begin(), nums.end());
        vector<vector<int>> ans;
        for (int i = 0; i < len; i++) {
            int l = i + 1, r = len - 1;
            while (l < r) {
                if (nums[l] + nums[r] > -nums[i]) r--;
                else if (nums[l] + nums[r] < -nums[i]) l++;
                else {
                    ans.push_back({nums[i], nums[l], nums[r]});
                    l++, r--;
                    while (l < r && nums[l - 1] == nums[l]) l++;
                    while (r > l && nums[r] == nums[r + 1]) r--;
                } 
            }
            while (i + 1 < len && nums[i] == nums[i + 1]) i++;
        }
        return ans;
    }
};