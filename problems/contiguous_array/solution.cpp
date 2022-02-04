class Solution {
public:
    int findMaxLength(vector<int>& nums) {
        int len = nums.size();
        vector<int> pre(len + 1);
        for (int i = 1; i <= len; i++) 
            pre[i] = pre[i - 1]  + (nums[i - 1] ? 1 : -1);
        unordered_map<int, int> mp;
        int ans = 0;
        mp[0] = 0;
        for (int i = 1; i <= len; i++) {
            if (mp.count(pre[i])) 
                ans = max(ans, i - mp[pre[i]]);
            else 
                mp[pre[i]] = i;
        }
        return ans;
    }
};