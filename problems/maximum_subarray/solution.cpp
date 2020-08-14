class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        if (nums.size() == 0) return 0;
        int _max = 0, ans = nums[0];
        for (int i = 0; i < nums.size(); i++) {
            _max += nums[i];
            ans = max(ans, _max);
            if (_max < 0) _max = 0;
        }
        return ans;
    }
};