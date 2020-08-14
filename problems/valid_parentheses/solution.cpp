class Solution {
public:
    bool isValid(string s) {
        stack<int> stk;
        int i = 0;
        int len = s.size();
        bool ok = true;
        auto get = [](char ch) {
            if (ch == '(' || ch == '{' || ch == '[') return true;
            return false;
        };
        auto check = [](char ch) {
            if (ch == ')') return '(';
            if (ch == '}') return '{';
            if (ch == ']') return '[';
            return '(';
        };
        while (i < len) {
            auto ch = s[i];
            if (get(ch)) stk.push(ch);
            else {
                if (stk.empty() || stk.top() != check(ch)) {
                    ok = false;
                    break;
                }
                stk.pop();
            }
            i++;
        }
        if (!stk.empty()) return false;
        return ok;
    }
};