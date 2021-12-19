class Solution {
public:
    string decodeString(string s) {
        int len = s.size();
        int i = 0;
        function<string()> dfs = [&]() {
            if (i == len) return string("");
            string str, tt;
            int cnt = 0;
            for (; i < len; i++) {
                if (s[i] == '[') {
                    i++;
                    tt = dfs();
                    while (cnt--) str += tt;
                    cnt = 0;
                }
                else if (s[i] == ']') return str;
                else {
                    if (s[i] >= '0' && s[i] <= '9') cnt = cnt * 10 + (s[i] - '0');
                    else str += s[i];
                }
            }
            return str;
        };
        return dfs();
    }
};