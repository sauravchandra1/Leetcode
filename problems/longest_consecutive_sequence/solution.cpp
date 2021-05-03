class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        int len = nums.size();
        sort(nums.begin(), nums.end());
        int ans = min(len, 1);
        int curr = ans;
        for (int i = 1; i < len; i++) {
            if (nums[i] == nums[i - 1]) continue;
            if (nums[i] == nums[i - 1] + 1) {
                curr++;
            } else {
                ans = max(ans, curr);
                curr = 1;
            }
        }
        ans = max(ans, curr);
        return ans;
    }
};