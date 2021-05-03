class Solution {
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        unordered_map<string, bool> mp;
        int len = wordDict.size();
        for (int i = 0; i < len; i++) mp[wordDict[i]] = true;
        vector<int> dp(s.size() + 1, -1);
        function<int(int)> dfs = [&](int idx) {
            if (idx == s.size()) return 1;
            auto& res = dp[idx];
            if (res != -1) return res;
            string temp;
            res = 0;
            for (int i = idx; i < s.size(); i++) {
                temp += s[i];
                if (mp.count(temp) > 0 && dfs(i + 1)) {
                    res = 1;
                    break;
                }
            }
            return res;
        };
        return dfs(0);
    }
};