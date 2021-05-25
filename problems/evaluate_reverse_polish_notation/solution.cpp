class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        stack<int> stk;
        auto isOperation = [&](string str) {
            if (str[0] >= '0' && str[0] <= '9' || str.size() > 1) return false;
            else return true;
        };
        auto getInt = [&](string str) {
            int num = 0;
            int neg = 1;
            for (auto& c : str) {
                if (c == '-') neg = -1;
                else num = num * 10 + (c - '0');
            }
            num *= neg;
            return num;
        };
        for (auto& c : tokens) {
            if (isOperation(c)) {
                int b = stk.top();
                stk.pop();
                int a = stk.top();
                stk.pop();
                int res = 0;
                char op = c[0];
                switch(op) {
                    case '+':
                        res = a + b;
                        break;
                    case '-':
                        res = a - b;
                        break;
                    case '/':
                        res = a / b;
                        break;
                    default:
                        res = a * b;
                        break;
                }
                stk.push(res);
            } else stk.push(getInt(c));
        }
        return stk.top();
    }
};