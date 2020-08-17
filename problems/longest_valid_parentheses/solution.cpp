class Solution {
public:
        int longestValidParentheses(string s) {
        int n = s.length(), ret = 0;
        vector < int > memo(n, 0);
        stack < pair < int, int >> st;
        for (int i = 0; i < n; ++i) {
            if (s[i] == '(')
                st.push({
                    i,
                    i > 0 ? memo[i - 1] : 0
                });
            else
            if (!st.empty()) {
                auto t = st.top();
                st.pop();
                memo[i] = t.second + 2;
                if (t.first != i - 1)
                    memo[i] += memo[i - 1];
            }
            ret = max(ret, memo[i]);
        }
        return ret;
    }
};