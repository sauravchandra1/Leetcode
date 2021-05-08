class Solution {
public:
    void sortColors(vector<int>& nums) {
        int len = nums.size();
        int l = 0, r = len - 1;
        for (int i = 0; i < len; i++) {
            if (nums[i] == 2) {
                while (r >= 0 && nums[r] == 2) r--;
                if (r >= 0 && r > i) {swap(nums[r], nums[i]);
                if (nums[i] == 0) i--;
                }
            } else if (nums[i] == 0) {
                while (l < len && nums[l] == 0) l++;
                if (l < len && l < i) swap(nums[l], nums[i]);
            }
        }
    }
};