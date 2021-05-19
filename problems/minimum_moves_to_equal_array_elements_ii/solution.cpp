class Solution {
public:
    int minMoves2(vector<int>& nums) {
        const int inf = 1e9;
        sort(nums.begin(), nums.end());
        int mid = 0;
        long long ans = 0, _min = 0;
        int len = nums.size();
        if (len % 2) {
            mid = nums[len / 2];
            for (auto& v : nums) ans += abs(v - mid);
        }
        else {
            mid = nums[(len / 2) - 1] + nums[len / 2];
            mid /= 2;
            for (auto& v : nums) ans += abs(v - mid);
            mid++;
            for (auto& v : nums) _min += abs(v - mid);
            ans = min(ans, _min);
        }
        return ans;
    }
};