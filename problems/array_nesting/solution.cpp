class Solution {
public:
    int arrayNesting(vector<int>& nums) {
        int len = nums.size();
        vector<bool> seen(len);
        int res = 0, ans, idx;
        for (int i = 0; i < len; i++) {
            if (!seen[i]) {
                seen[i] = true;
                idx = nums[i];
                ans = 1;
                while (!seen[idx]) {
                    ans++;
                    seen[idx] = true;
                    idx = nums[idx];
                }
                res = max(res, ans);
            }
        }
        return res;
    }
};