class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        if (nums.size() == 0) return 0;
        int unique = 1;
        for (int i = 1; i < nums.size(); i++) {
            while (i < nums.size() && nums[i] == nums[i - 1]) i++;
            if (i < nums.size()) nums[unique++] = nums[i];
        }
        return unique;
    }
};