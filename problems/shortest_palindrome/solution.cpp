class Solution {
    public:
        string shortestPalindrome(string s) {
            int n = s.length();
            if (!n) return "";
            string d = s;
            string temp = s + '?';
            reverse(s.begin(), s.end());
            temp += s;
            int m = temp.length();
            int lps[m + 1];
            memset(lps, 0, sizeof(lps));
            for (int i = 1; i <= m; i++) {
                int len = lps[i - 1];
                while (len > 0 and temp[i] != temp[len])
                    len = lps[len - 1];
                if (temp[i] == temp[len])
                    len++;
                lps[i] = len;
            }
            int mxLen = lps[m - 1];
            string z = d.substr(mxLen);
            reverse(z.begin(), z.end());
            string ans = z + d;
            return ans;
        }
};