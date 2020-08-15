class Solution {
public:
    int search(vector<int>& nums, int target) {
        int len = nums.size();
        for (int i = 0; i < len; i++) {
            if (target == nums[i]) return i;
        }
        return -1;
    }
};