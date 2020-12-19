class Solution {
public:
    int titleToNumber(string s) {
        int idx = s.size() - 1;
        int ans = 0;
        for (int i = 0; i < s.size(); i++) {
            auto ch = s[s.size() - i - 1];
            ans += pow(26, i) * (ch - 'A' + 1);
        }
        return ans;
    }
};