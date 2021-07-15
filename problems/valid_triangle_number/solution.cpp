class Solution {
public:
    int triangleNumber(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int ans = 0, id;
        for (int i = 0; i < nums.size(); i++) {
            for (int j = i + 1; j < nums.size(); j++) {
                id = lower_bound(nums.begin(), nums.end(), nums[i] + nums[j]) - nums.begin();
                ans += max(0, id - 1 - j);
            }
        }
        return ans;
    }
};