class Solution {
public:
    vector<vector<string>> partition(string s) {
        int len = s.size();
        vector<vector<vector<string>>> dp(len + 1);
        vector<int> dp1(len, -1);
        vector<vector<int>> palin(len, vector<int>(len, -1));
        auto isPalin = [&](string a) {
            string b = a;
            reverse(a.begin(), a.end());
            return (a == b);
        };
        function<vector<vector<string>>(int)> dfs = [&](int idx) {
            if (idx == len) 
                return dp[len];
            auto& res = dp[idx];
            if (dp1[idx] != -1) return res;
            dp1[idx] = 0;
            string temp;
            for (int i = idx; i < len; i++) {
                temp += s[i];
                if (palin[idx][i] == -1) palin[idx][i] = isPalin(temp);
                if (palin[idx][i]) {
                    auto ss = dfs(i + 1);
                    for (auto v : ss) {
                        v.insert(v.begin(), temp);
                        res.push_back(v);
                    }
                    if (i + 1 == len) res.push_back({temp});
                }
            }
            return res;
        };
        return dfs(0);
    }
};