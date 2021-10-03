class Solution {
public:
    bool canJump(vector<int>& nums) {
        int curr = nums[0];
        for (int i = 1; i < nums.size(); i++) {
            if (curr < i) return false;
            curr = max(curr, i + nums[i]);
        }
        return true;
    }
};