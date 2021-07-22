class Solution {
public:
    int partitionDisjoint(vector<int>& nums) {
        int len = nums.size();
        vector<int> vec(len);
        vec[len - 1] = nums[len - 1];
        for (int i = len - 2; i >= 1; i--) vec[i] = min(vec[i + 1], nums[i]);
        int max_so_far = nums[0];
        for (int i = 1; i < nums.size(); i++) {
            if (max_so_far <= vec[i]) return i;
            max_so_far = max(max_so_far, nums[i]);
        }
        return 0;
    }
};