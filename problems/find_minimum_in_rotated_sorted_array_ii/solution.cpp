class Solution {
public:
    int findMin(vector<int>& nums) {
        int len = nums.size();
        int l = 0, r = len - 1;
        function<int(int, int)> dfs = [&](int l, int r) {
            if (l > r) return 1000000009;
            while (l < r) {
                int m = (l + r) / 2;
                if (nums[m] == nums[l] && nums[m] == nums[r]) {
                    l = dfs(l, m - 1);
                    r = dfs(m + 1, r);
                    return min(l, r);
                }
                else if (nums[m] > nums[r]) l = m + 1;
                else if (nums[m] < nums[l]) r = m;
                else break;
            }
            return nums[l];
        };
        return dfs(l, r);
    }
};