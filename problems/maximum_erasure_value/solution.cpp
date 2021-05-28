class Solution {
public:
    int maximumUniqueSubarray(vector<int>& nums) {
        unordered_map<int, int> mp;
        int ans = 0, sum = 0;
        int l = 0;
        for (int i = 0; i < nums.size(); i++) {
            sum += nums[i];
            if (mp.count(nums[i]) > 0) {
                while (l <= mp[nums[i]]) {
                    sum -= nums[l];
                    l++;
                }   
            }
            mp[nums[i]] = i;
            ans = max(ans, sum);
        }
        return ans;
    }
};