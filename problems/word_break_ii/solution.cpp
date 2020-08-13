class Solution {
public:
    vector<string> wordBreak(string s, vector<string>& wordDict) {
        int n = s.size();
        unordered_set<string> ump;
        vector<bool> dp2(n, false);
        for (auto v : wordDict) ump.insert(v);
        vector<vector<string>> dp(n);
        function<vector<string>(int)> dfs = [&](int idx) {
            vector<string> ans;
            if (idx == n) return ans; 
            string str, tt;
            auto &res = dp[idx];
            if (dp2[idx]) return res;
            for (int i = idx; i < n; i++) {
                str += s[i];
                if (ump.find(str) != ump.end()) {
                    ans = dfs(i + 1);
                    for (auto v : ans) {
                        tt = str + " " + v;
                        res.push_back(tt);
                    }
                    if (i + 1 == n) res.push_back(str);
                }
            }
            dp2[idx] = true;
            return res;
        };
        return dfs(0);
    }
};