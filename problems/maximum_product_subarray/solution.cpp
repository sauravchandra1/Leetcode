class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int _max = nums[0], _min = nums[0];
        int ans = _max;
        for (int i = 1; i < nums.size(); i++) {
            if (nums[i] < 0) swap(_max, _min); 
            _max = max(nums[i], nums[i] * _max);
            _min = min(nums[i], nums[i] * _min);
            ans = max(ans, _max);
        }
        return ans;
    }
};