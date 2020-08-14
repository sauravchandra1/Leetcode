class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int, int> ump;
        for (auto v : nums) {
            ump[v]++;
        }
        set<pair<int, int>> se;
        for (auto v : ump) {
            se.insert({v.second, v.first});
        }
        set<pair<int, int>> :: iterator it = se.end();
        it--;
        vector<int> vec;
        while (k--) {
            vec.push_back(it->second);
            it--;
        }
        return vec;
    }
};