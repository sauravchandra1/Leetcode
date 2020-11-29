class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        string ans;
        int len = strs.size();
        if (len == 0) return ans;
        for (int i = 0; i < strs[0].size(); i++) {
            char ch = '#';
            for (int j = 0; j < len; j++) {
                if (i >= strs[j].size()) return ans;
                if (ch == '#') ch = strs[j][i];
                else {
                    if (strs[j][i] != ch) return ans;
                }
            }
            if (ch != '#') ans += ch;
        }
        return ans;
    }
};