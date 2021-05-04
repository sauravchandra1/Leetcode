class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        unordered_map<int, int> mp;
        int len = nums.size();
        for (int i = 0; i < len; i++) mp[nums[i]] = i;
        vector<int> vec(3);
        vector<vector<int>> ans;
        for (int i = 0; i < len - 2; i++) {
            vec[0] = nums[i];
            for (int j = i + 1; j < len - 1; j++) {
                vec[1] = nums[j];
                int sum = vec[0] + vec[1];
                if (mp.count(-sum) && mp[-sum] > j) {
                    vec[2] = -sum;
                    ans.push_back(vec);
                }
                while (j < len - 1 && nums[j] == nums[j + 1]) j++;
            }
            while (i < len - 2 && nums[i] == nums[i + 1]) i++;
        }
        return ans;
    }
};