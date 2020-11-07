class Solution {
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        int len = s.size();
        unordered_set<string> ump;
        for (auto v : wordDict) ump.insert(v);
        vector<int> dp(len + 1, -1);
        function<int(int)> dfs = [&](int idx) {
            if (idx == len) return 1;
            auto& ans = dp[idx];
            if (ans != -1) return ans;
            ans = 0;
            string str;
            for (int i = idx; i < len; i++) {
                str += s[i];
                if (ump.find(str) != ump.end())
                    ans = dfs(i + 1);
                if (ans) break;
            }
            return ans;
        };
        auto res = dfs(0);
        return (bool)res;
    }
};