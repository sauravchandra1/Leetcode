class Solution {
public:
    int singleNonDuplicate(vector<int>& nums) {
        int len = nums.size();
        int l = 0, r = len - 1, m;
        while (l < r) {
            m = (l + r) / 2;
            if (m + 1 < len && nums[m] == nums[m + 1]) {
                if ((len - m) % 2 == 0) r = m - 1;
                else l = m + 2;
            }
            else if (m - 1 >= 0 && nums[m] == nums[m - 1]) {
                if ((m + 1) % 2 == 0) l = m + 1;
                else r = m - 2;
            }
            else return nums[m];
        }
        return nums[l];
    }
};