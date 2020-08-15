class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        int ans = 0;
        unordered_map<int, int> mp;
        int sum = 0;
        for (auto v : nums) {
            mp[sum]++;
            sum += v;
            ans += mp[sum - k];
        }
        return ans;
    }
};