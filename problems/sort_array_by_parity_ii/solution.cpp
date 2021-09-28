class Solution {
public:
    vector<int> sortArrayByParityII(vector<int>& nums) {
        int len = nums.size();
        int l = 0, r = 1;
        while (l < len && r < len) {
            if (!(nums[l] & 1)) {
                l += 2;
                continue;
            }
            if (nums[r] & 1) {
                r += 2;
                continue;
            }
            swap(nums[l], nums[r]);
            l += 2;
            r += 2;
        }
        return nums;
    }
};