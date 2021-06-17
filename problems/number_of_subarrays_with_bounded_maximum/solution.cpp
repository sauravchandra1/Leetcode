class Solution {
public:
    int numSubarrayBoundedMax(vector<int>& nums, int left, int right) {
        auto get = [&](int val) {
            if (val >= left && val <= right) return 0;
            else if (val < left) return 1;
            else return 2;
        };
        vector<pair<int, int>> vec;
        int i = 0, type = -1, count = 0;
        while (i < nums.size()) {
            if (get(nums[i]) != type) {
                if (count > 0) vec.push_back({type, count});
                count = 1;
                type = get(nums[i]);
            } else count++;
            i++;
        }
        if (count > 0) vec.push_back({type, count});
        int len = vec.size(), ans = 0, cnt = 0;
        for (int i = 0; i < len; i++) {
            type = vec[i].first, count = vec[i].second;
            if (type == 2) {
                ans += (cnt * (cnt + 1)) / 2;
                cnt = 0;
            } else {
                cnt += count;
                if (type == 1)
                    ans -= (count * (count + 1)) / 2;
            }
        }
        if (cnt) ans += (cnt * (cnt + 1)) / 2;
        return ans;
        
    }
};