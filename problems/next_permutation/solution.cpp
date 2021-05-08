class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        int len = nums.size();
        for (int i = len - 1; i > 0; i--) {
            if (nums[i - 1] < nums[i]) {
                int just_greater = 101;
                int idx = 0;
                for (int j = i; j < len; j++) {
                    if (nums[j] > nums[i - 1] && nums[j] <= just_greater) {
                        just_greater = nums[j];
                        idx = j;
                    }
                }
                swap(nums[i - 1], nums[idx]);
                int l = i, r = len - 1;
                while (l < r) {
                    swap(nums[l], nums[r]);
                    l++, r--;
                }
                return;
            }
        }
        int l = 0, r = len - 1;
        while (l < r) {
            swap(nums[l], nums[r]);
            l++, r--;
        }
    }
};