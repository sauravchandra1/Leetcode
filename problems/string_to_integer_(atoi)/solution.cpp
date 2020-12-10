class Solution {
public:
    int myAtoi(string s) {
        long long ans = 0;
        const int N = 31;
        long long lim = (1LL << N);
        bool space = true, plus = true, sign = true, num = true;
        for (int i = 0; i < s.size(); i++) {
            if (space && s[i] == ' ') continue;
            if (s[i] != ' ') space = false;
            if (sign && (s[i] == '+' || s[i] == '-')) {
                if (s[i] == '-') plus = false;
                sign = false;
                continue;
            }
            if (ans > lim) break;
            if (num && s[i] >= '0' && s[i] <= '9') {
                ans = ans * 10LL + (s[i] - '0');
                sign = false;
            }
            if (!space && num && !(s[i] >= '0' && s[i] <= '9')) {
                num = false;
            } 
            if (!num) break;
        }
        if (plus && ans > lim - 1) ans = lim - 1;
        if (!plus && ans > lim) ans = -lim;
        if (!plus) ans *= -1;
        return ans;
    }
};