class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        int ans = 0, curr = 0;
        int len = nums.size();
        for (int i = 0; i < len; i++) {
            if (nums[i] != 1) {
                ans = max(ans, curr);
                curr = 0;
            } else {
                curr++;
            }
        }
        ans = max(ans, curr);
        return ans;
    }
};