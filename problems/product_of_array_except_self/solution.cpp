class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int m = 1;
        for (auto v : nums) {
            if (v == 0) continue;
            m *= v;
        }
        vector<int> z;
        for (int i = 0; i < nums.size(); i++) {
            if (nums[i] == 0) {
                z.push_back(i);
            }
        }
        vector<int> ans;
        if (z.size() > 1) {
            ans.resize(nums.size(), 0);
            return ans;
        }
        if (z.size() == 1) {
            ans.resize(nums.size(), 0);
            ans[z[0]] = m;
            return ans;
        }
        for (auto v : nums) {
            ans.push_back(m / v);
        }
        return ans;
    }
};