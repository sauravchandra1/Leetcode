class Solution {
public:
    int minStartValue(vector<int>& nums) {
        int ans = 1, sum = 0;
        for (auto v : nums) {
            sum += v;
            if (sum <= 0) ans = max(ans, 1 - sum);
        }
        return ans;
    }
};