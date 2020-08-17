class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        unordered_map<int, int> mp;
        for (auto v : nums) mp[v]++;
        for (auto v : mp) if (v.second >= 2) return v.first;
        return 0;
    }
};