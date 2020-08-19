class Solution {
    public:
        string longestCommonPrefix(vector < string > & strs) {
            if (strs.size() == 0)
                return "";
            string s = strs[0];
            for (int i = 1; i < strs.size(); i++) {
                if (strs[i].length() < s.length()) {
                    s = strs[i];
                }
            }
            string ans = "";
            for (int i = 0; i < s.length(); i++) {
                for (int j = 0; j < strs.size(); j++) {
                    if (strs[j][i] != s[i])
                        return ans;
                }
                ans += s[i];
            }
            return ans;
        }
};