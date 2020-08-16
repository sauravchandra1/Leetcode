class Solution {
    public:
        string evaluate(string t) {
            int n = t.size();
            if (n == 1)
                return t;
            for (int i = 1; i < n; i++) {
                if (t[i] == '-') {
                    if (t[i - 1] == '+') {
                        t.erase(i - 1, 1);
                        i--;
                    }
                    if (t[i - 1] == '-') {
                        t[i] = '+';
                        t.erase(i - 1, 1);
                        i--;
                    }
                }
            }
            stringstream ss(t);
            int ans = 0;
            int a;
            while (ss >> a)
                ans += a;
            return to_string(ans);
        }
    int calculate(string s) {
        s.insert(0, "(");
        s.push_back(')');
        stack < string > st;
        string t = "";
        for (int i = 0; i < s.size(); i++) {
            if (s[i] == ' ')
                continue;
            else if (s[i] == '(') {
                if (t != "")
                    st.push(t);
                st.push("(");
                t = "";
            } else if (s[i] == ')') {
                t = evaluate(t);
                st.pop();
                if (!st.empty() && st.top() != "(") {
                    t = st.top() + t;
                    st.pop();
                }
            } else
                t += s[i];

        }
        return stoi(t);
    }
};