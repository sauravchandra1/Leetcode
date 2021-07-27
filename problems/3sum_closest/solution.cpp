class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        sort(nums.begin(), nums.end());
        int len = nums.size();
        int ans, val, idx, tt;
        ans = nums[0] + nums[1] + nums[2];
        for (int i = 0; i < len; i++) {
            for (int j = i + 1; j < len; j++) {
                tt = nums[i] + nums[j];
                val = target - tt;
                idx = lower_bound(nums.begin() + j + 1, nums.end(), val) - nums.begin();
                if (idx < len) {
                    if (val == nums[idx]) return target;
                    if (abs(target - (nums[idx] + tt)) < abs(target - ans)) ans = nums[idx] + tt;
                }
                if (idx - 1 > j && abs(target - (nums[idx - 1] + tt)) < abs(target - ans)) ans = nums[idx - 1] + tt;
            }
        }
        return ans;
    }
};