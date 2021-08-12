class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        const int N = 26;
        int n = strs.size();
        vector<vector<int>> cnt(n, vector<int>(N, 0));
        vector<vector<string>> ans;
        for (int i = 0; i < n; i++) 
            for (auto& v : strs[i]) 
                cnt[i][v - 'a']++;
        vector<int> idx(n);
        iota(idx.begin(), idx.end(), 0);
        sort(idx.begin(), idx.end(), [&](const int& i, const int& j) {
            int l1 = strs[i].size(), l2 = strs[j].size();
            for (int k = 0; k < N; k++) {
                l1 -= cnt[i][k], l2 -= cnt[j][k];
                if (!l1 && !l2) return (cnt[i][k] < cnt[j][k]);
                else if (l1 == 0) return true;
                else if (l2 == 0) return false;
                if (cnt[i][k] == cnt[j][k]) continue;
                else return (cnt[i][k] > cnt[j][k]);
            }
            return true;
        });
        auto get = [&](int i, int j) {
            if (strs[i].size() != strs[j].size()) return false;
            for (int k = 0; k < N; k++) 
                if (cnt[i][k] != cnt[j][k]) 
                    return false;
            return true;
        };
        vector<string> vec;
        vec.push_back(strs[idx[0]]);
        for (int i = 1; i < n; i++) {
            if (get(idx[i], idx[i - 1])) vec.push_back(strs[idx[i]]);
            else {
                ans.push_back(vec);
                vec.clear();
                vec.push_back(strs[idx[i]]);
            }
        }
        ans.push_back(vec);
        return ans;
    }
};