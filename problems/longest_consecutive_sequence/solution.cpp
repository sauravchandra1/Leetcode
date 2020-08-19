class Solution {
    public:
        int longestConsecutive(vector < int > & nums) {
            int n = nums.size();
            if (n == 0)
                return 0;
            int maxx = 1, longest_maxx = 1;
            sort(nums.begin(), nums.end());
            for (int i = 1; i < n; i++) {
                if (nums[i] != nums[i - 1]) {
                    if (nums[i] == (nums[i - 1] + 1)) {
                        maxx += 1;
                    } else {
                        longest_maxx = max(longest_maxx, maxx);
                        maxx = 1;
                    }
                }

            }
            return max(maxx, longest_maxx);
        }
};