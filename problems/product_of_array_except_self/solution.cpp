class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int len = nums.size();
        vector<int> ans(len, 1);
        int right = nums[len - 1];
        for (int i = len - 2; i >= 0; i--) {
            ans[i] = right;
            right *= nums[i];
        }
        int left = nums[0];
        for (int i = 1; i < len; i++) {
            ans[i] *= left;
            left *= nums[i];
        }
        return ans;
    }
};