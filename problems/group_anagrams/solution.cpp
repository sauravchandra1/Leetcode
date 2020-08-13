class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        vector<vector<string>> ans;
        unordered_map<string, vector<int>> mp;
        int len = strs.size();
        vector<string> cpy(strs);
        for (int i = 0; i < len; i++) {
            sort(strs[i].begin(), strs[i].end());
            mp[strs[i]].push_back(i);
        }
        for (auto elem : mp) {
            vector<string> vec;
            for (auto v : elem.second) {
                vec.push_back(cpy[v]);
            }
            ans.push_back(vec);
        }
        return ans;
    }
};