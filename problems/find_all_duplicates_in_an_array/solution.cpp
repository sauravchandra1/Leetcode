class Solution {
public:
    vector<int> findDuplicates(vector<int>& nums) {
        unordered_map<int, int> ump;
        for (auto v : nums) ump[v]++;
        vector<int> ans;
        for (auto v : ump) if (v.second >= 2) ans.push_back(v.first);
        return ans;
    }
};