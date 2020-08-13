class Solution {
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        int n = s.size();
        unordered_set<string> ump;
        for (auto v : wordDict) ump.insert(v);
        vector<int> dp(n, -1);
        bool ok = false;
        function<int(int)> dfs = [&](int idx) {
            if (idx == n) return 1; 
            int &res = dp[idx];
            if (res != -1) return res;
            res = 0;
            string str;
            for (int i = idx; i < n; i++) {
                str += s[i];
                if (ump.find(str) != ump.end()) {
                    res = dfs(i + 1);
                    if (res) return res;
                }
            }
            return res;
        };
        return (bool)dfs(0);
    }
};