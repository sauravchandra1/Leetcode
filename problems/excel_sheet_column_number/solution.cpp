class Solution {
public:
    int titleToNumber(string s) {
        int ans = 0;
        auto pwr = [&](long long x, long long y) {
            long long res = 1;
            while (y > 0) {
                if (y & 1) {
                    res = res * x;
                }
                y = y >> 1;
                x = x * x;
            }
            return res;
        };
        for (int i = s.size() - 1; i >= 0; i--) {
            ans += pwr(26, s.size() - i - 1) * (s[i] - 'A' + 1);
        }
        return ans;
    }
};