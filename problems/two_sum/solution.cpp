class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int, int> mp, mp1;
        for (int i = 0; i < nums.size(); i++) mp[nums[i]] = i;
        for (int i = nums.size() - 1; i >= 0; i--) mp1[nums[i]] = i;
        sort(nums.begin(), nums.end());
        int l = 0, r = nums.size() - 1;
        while (l < r) {
            if (nums[l] + nums[r] > target) r--;
            else if (nums[l] + nums[r] < target) l++;
            else return {mp[nums[l]], mp1[nums[r]]};
        }
        return {0, 1};
    }
};