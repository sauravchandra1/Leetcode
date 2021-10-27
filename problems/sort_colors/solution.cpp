class Solution {
public:
    void sortColors(vector<int>& nums) {
        int len = nums.size();
        int i = 0, j = 1, k = 2;
        if (len == 2 && nums[0] > nums[1]) swap(nums[0], nums[1]);
        while (i < len && j < len && k < len) {
            while (i < len && nums[i] == 0) i++;
            j = i;
            while (j < len && nums[j] == 1) j++;
            k = j;
            while (k < len && nums[k] == 2) k++;
            if (j < len && i < len && nums[j] < nums[i]) swap(nums[j], nums[i]);
            if (k < len && i < len && nums[k] < nums[i]) swap(nums[k], nums[i]);
            if (k < len && j < len && nums[k] < nums[j]) swap(nums[k], nums[j]);
        }
    }
};