class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        int len = nums.size();
        unordered_map<int, int> mp;
        set<vector<int>> se;
        vector<int> vec(4, 0);
        vector<vector<int>> ans;
        int a, b, c, d;
        sort(nums.begin(), nums.end());
        for (int i = 0; i < len; i++) mp[nums[i]] = i;
        for (int i = 0; i < len; i++) {
            a = nums[i];
            vec[0] = a;
            for (int j = i + 1; j < len; j++) {
                b = nums[j];
                vec[1] = b;
                for (int k = j + 1; k < len; k++) {
                    c = nums[k];
                    vec[2] = c;
                    d = target - (a + b + c);
                    if (mp[d] > k) {
                        vec[3] = d;
                        se.insert(vec);
                    }
                }
            }
        }
        for (auto v : se) ans.push_back(v);
        return ans;
    }
};