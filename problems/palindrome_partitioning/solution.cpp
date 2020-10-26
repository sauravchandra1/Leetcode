class Solution {
public:
    vector<vector<string>> partition(string s) {
        int len = s.size();
        vector<vector<string>> ans;
        vector<string> res;
        auto chk = [&](string str) {
            auto cpy = str;
            reverse(str.begin(), str.end());
            if (cpy == str) return true;
            else return false;
        };
        function<void(string, int)> dfs = [&](string str, int idx) {
            if (idx == len) {
                ans.push_back(res);
                return ;
            }
            for (int i = idx; i < len; i++) {
                str += s[i];
                if (chk(str)) {
                    res.push_back(str);
                    dfs("", i + 1);
                    res.pop_back();
                }
            }
        };
        dfs("", 0);
        return ans;
    }
};