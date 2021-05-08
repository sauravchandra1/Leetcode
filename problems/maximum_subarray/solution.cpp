class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int _max = nums[0];
        bool isNeg = true;
        int max_so_far = 0, ans = 0;
        for (int i = 0; i < nums.size(); i++) {
            max_so_far += nums[i];
            if (nums[i] >= 0) isNeg = false;
            _max = max(_max, nums[i]);
            if (max_so_far < 0) {
                max_so_far = 0;
            }
            ans = max(ans, max_so_far);
        }
        if (isNeg) return _max;
        return ans;
    }
};