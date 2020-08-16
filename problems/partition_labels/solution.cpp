class Solution {
public:
    vector<int> partitionLabels(string S) {
        int len = S.size();
        unordered_map<char, pair<int, int>> mp;
        for (int i = 0; i < len; i++) {
            if (mp.count(S[i]) > 0) {
                mp[S[i]].second = i;
            } else {
                mp[S[i]].first = i;
                mp[S[i]].second = i;
            }
        }
        char c;
        vector<int> ans;
        int cnt = 0;
        int l = 0;
        for (int i = 0; i < len; i++) {
            c = S[i];
            if (i == 0) {
                l = mp[c].second;
            }
            if (i <= l) {
                cnt++;
                l = max(l, mp[c].second);
            } else {
                ans.push_back(cnt);
                cnt = 1;
                l = mp[c].second;
            }
        }
        if (cnt) {
            ans.push_back(cnt);
        }
        return ans;
    }
};