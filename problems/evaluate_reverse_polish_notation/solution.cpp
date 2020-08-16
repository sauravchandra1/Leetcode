class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        int ans = 0;
        stack<int> stk;
        int len = tokens.size();
        int a, b;
        if (len == 0) return 0;
        for (auto v : tokens) {
            if (v.size() == 1 && v[0] < '0') {
                b = stk.top();
                stk.pop();
                a = stk.top();
                stk.pop();
                if (v[0] == '+') {
                    stk.push(a + b);
                } else if (v[0] == '-') {
                    stk.push(a - b);
                } else if (v[0] == '*') {
                    stk.push(a * b);
                } else if (v[0] == '/') {
                    stk.push(a / b);
                } 
            }
            else {
                if (v[0] == '-') stk.push(stoi(v.substr(1)) * -1);
                else stk.push(stoi(v));
            }
        }
        return stk.top();
    }
};