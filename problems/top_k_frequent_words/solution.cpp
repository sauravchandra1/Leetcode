class Solution {
public:
    vector<string> topKFrequent(vector<string>& words, int k) {
        unordered_map<string, int> mp;
        for (auto v : words) mp[v]++;
        vector<pair<int, string>> ans;
        for (auto v : mp) {
            ans.push_back({v.second, v.first});
        }
        sort(ans.begin(), ans.end(), [](const pair<int, string>& a, 
                                        const pair<int, string>& b) {
            if (a.first == b.first) {
                return (a.second < b.second);
            } else {
                return (a.first > b.first);
            }
        });
        vector<string> res;
        for (int i = 0; i < k; i++) {
            res.push_back(ans[i].second);
        }
        return res;
    }
};