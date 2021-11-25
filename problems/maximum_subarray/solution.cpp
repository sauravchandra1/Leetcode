class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int ans = 0;
        int _max = -1e9;
        for (int i = 0; i < nums.size(); i++) {
            ans += nums[i];
            if (ans > _max) _max = ans;
            if (ans < 0) ans = 0;
        }
        return _max;
    }
};