class Solution {
public:
    bool canJump(vector<int>& nums) {
        int len = nums.size();
        int pos = 0, des = 0, ans = 0;
        for (int i = 0; i < len - 1; i++) {
            if (i > des) return false;
            des = max(des, nums[i] + i);
        }
        if (des >= len - 1) return true;
        return false;
    }
};