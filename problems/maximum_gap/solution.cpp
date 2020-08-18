class Solution {
public:
    int maximumGap(vector<int>& nums) {
        int ans = 0;
        if (nums.size() == 0) return ans;
        sort(nums.begin(), nums.end());
        for (int i = 0; i < nums.size() - 1; i++) {
            ans = max(ans, nums[i + 1] - nums[i]);
        }
        return ans;
    }
};