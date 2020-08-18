class Solution {
public:
    vector<string> summaryRanges(vector<int>& nums) {
        vector<string> ans;
        int len = nums.size();
        if (len == 0) return ans;
        for (int i = 0; i < len; i++) {
            int l = i;
            while (i + 1 < len && nums[i + 1] == nums[i] + 1) i++;
            if (l == i) {
                ans.push_back(to_string(nums[i]));
            } else {
                ans.push_back(to_string(nums[l]) + "->" + to_string(nums[i]));
            }
        }
        return ans;
    }
};