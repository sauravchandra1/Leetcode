class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        if (nums.size() == 0) return 0;
        int ans = 1, _max = 1;
        for (int i = 1; i < nums.size(); i++) {
            if (nums[i] == nums[i - 1]) continue;
            if (nums[i] == nums[i - 1] + 1) ans++;
            else {
                _max = max(_max, ans);
                ans = 1;
            }
        }
        _max = max(_max, ans);
        return _max;
    }
};