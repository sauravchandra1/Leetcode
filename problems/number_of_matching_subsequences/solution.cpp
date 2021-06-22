class Solution {
public:
    int numMatchingSubseq(string s, vector<string>& words) {
        int len = s.size();
        const int N = 26;
        vector<vector<int>> index(len, vector<int>(N, -1));
        for (auto c = 'a'; c <= 'z'; c++) {
            int idx = -1;
            for (int i = len - 1; i >= 0; i--) {
                if (s[i] == c) idx = i;
                index[i][c - 'a'] = idx;
            }
        }
        auto Check = [&](string& str) {
            int idx = 0, i = 0;
            while (idx < len && i < str.size() && index[idx][str[i] - 'a'] != -1) {
                idx = index[idx][str[i] - 'a'] + 1;
                i++;
            }
            if (i == str.size()) return true;
            else return false;
        };
        int ans = 0;
        for (auto& str : words) if (Check(str)) ans++;
        return ans;
    }
};