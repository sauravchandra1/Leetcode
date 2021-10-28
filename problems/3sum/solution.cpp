class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        int len = nums.size();
        if (len < 3) return {};
        sort(nums.begin(), nums.end());
        unordered_map<int, bool> mp;
        for (auto& v : nums) mp[v] = true;
        int count_zero = upper_bound(nums.begin(), nums.end(), 0) -                                          lower_bound(nums.begin(), nums.end(), 0);
        vector<vector<int>> ans;
        if (count_zero >= 3) ans.push_back({0, 0, 0});
        for (int i = 0; i < len; i++) {
            if (nums[i] >= 0) break;
            for (int j = i + 1; j < len; j++) {
                if (nums[j] > 0) break;
                int v = nums[i] + nums[j];
                if (mp.count(-v)) 
                    ans.push_back({nums[i], nums[j], -v});
                while (j + 1 < len && nums[j] == nums[j + 1]) j++;
            }
            while (i + 1 < len && nums[i] == nums[i + 1]) i++;
        }
        for (int i = len - 1; i >= 0; i--) {
            if (nums[i] <= 0) break;
            for (int j = i - 1; j >= 0; j--) {
                if (nums[j] <= 0) break;
                int v = nums[i] + nums[j];
                if (mp.count(-v)) 
                    ans.push_back({nums[i], nums[j], -v});
                while (j - 1 >= 0 && nums[j] == nums[j - 1]) j--;
            }
            while (i - 1 >= 0 && nums[i] == nums[i - 1]) i--;
        }
        return ans;
    }
};