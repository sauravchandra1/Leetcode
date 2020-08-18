class Solution {
public:
    int calculate(string s) {
        stack<char> stk;
        stack<int> num;
        bool is_div = false, is_mul = false;
        for (int i = 0; i < s.size(); i++) {
            auto v = s[i];
            if (v == ' ') continue;
            if (v >= '0' && v <= '9') {
                int val = 0;
                while (i < s.size() && s[i] >= '0' && s[i] <= '9') {
                    val = val * 10 + (s[i] - '0');
                    i++;
                }
                i--;
                if (is_div || is_mul) {
                    int b = val;
                    int a = num.top();
                    num.pop();
                    if (is_div) {
                        val = a / b;
                        is_div = false;
                    } else {
                        val = a * b;
                        is_mul = false;
                    }
                }
                num.push(val);
            } else if (v == '/') {
                is_div = true;
            } else if (v == '*') {
                is_mul = true;
            } else {
                stk.push(v);
            }
        }
        int ans = 0;
        deque<char> lit;
        deque<int> val;
        while (!stk.empty()) {
            lit.push_front(stk.top());
            stk.pop();
        }
        while (!num.empty()) {
            val.push_front(num.top());
            num.pop();
        }
        while (!lit.empty()) {
            int a = val.front();
            val.pop_front();
            int b = val.front();
            val.pop_front();
            auto op = lit.front();
            lit.pop_front();
            if (op == '+') {
                ans = a + b;
            } else {
                ans = a - b;
            }
            val.push_front(ans);
        }
        if (!val.empty()) return val.front();
        return ans;
    }
};