class Solution {
public:
    bool find132pattern(vector<int>& nums) {
        int i, last;
        int l;
        int len = nums.size();
        if (len <= 2) return false;
        if (nums[0] <= nums[1]) {
            l = 0;
        } else {
            l = 1;
        }
        last = nums[l];
        i = 1;
        while (i < len) {
            while (i < len && nums[i] >= last) {
                last = nums[i];
                i++;
            }
            if (i == len) return false;
            int r = i;
            while (r < len) {
                if (nums[r] > nums[l] && nums[r] < last) return true;
                r++;
            }
            l = i;
            last = nums[i];
            i++;
        }
        return false;
    }
};