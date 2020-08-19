class Solution {
    public:
        int candy(vector < int > & nums) {
            int n = nums.size();
            if (n < 2) return n;
            int sum = 1, start = 0, left = 0, right = 0, peak = 0, i = 0;
            while (i < n - 1) {
                while (i < n - 1 && nums[i + 1] > nums[i]) i++; 
                left = i - start; 
                start = i; 
                while (i < n - 1 && nums[i + 1] < nums[i]) i++; 
                right = i - start; 
                start = right; 
                peak = max(left, right) + 1; 
                sum += (1 + left) * left / 2 + (1 + right) * right / 2 + peak - 1;
                while (i < n - 1 && nums[i + 1] == nums[i]) {
                    i++;
                    sum++;
                }
                start = i; 
            }
            return sum;
        }
};