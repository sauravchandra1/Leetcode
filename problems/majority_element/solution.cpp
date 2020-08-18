class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int len = nums.size();
        unordered_map<int, int> mp;
        for (auto v : nums) {
            mp[v]++;
            if (mp[v] > len / 2) return v;
        }
        return 0;
    }
};