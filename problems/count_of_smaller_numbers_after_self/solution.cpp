class Solution {
public:
    vector<int> countSmaller(vector<int>& nums) {
        int n = nums.size();
        if (n == 0) return {};
        vector<int> ans(n);
        int _min = *min_element(nums.begin(), nums.end());
        _min = abs(_min);
        _min++;
        for (auto &v : nums) {
            v += _min;
        }
        int _max = *max_element(nums.begin(), nums.end());
        vector<int> fenwick(_max + 1, 0);
        auto add = [&](int idx, int val) {
            while (idx <= _max) {
                fenwick[idx] += val;
                idx += idx & (-idx);
            }    
        };
        auto get = [&](int idx) {
            int sum = 0;
            while (idx > 0) {
                sum += fenwick[idx];
                idx -= idx & (-idx);
            }
            return sum;
        };
        for (int i = n - 1; i >= 0; i--) {
            ans[i] = get(nums[i] - 1);
            add(nums[i], 1);
        }
        return ans;
    }
};