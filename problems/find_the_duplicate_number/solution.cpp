class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        int len = nums.size();
        for (int i = 0; i < len; i++) {
            int val = nums[i];
            if (val < 0) val = -val;
            val -= 1;
            nums[val] = -nums[val];
            if (nums[val] > 0) return val + 1;
        }
        return 0;
    }
};