class Solution {
public:
    int divide(int dividend, int divisor) {
        long long int N = 31;
        long long int lim = (1LL << N);
        long long int d1 = dividend;
        long long int d2 = divisor;
        long long int ans = d1 / d2;
        if (ans < -lim || ans > lim - 1) return lim - 1;
        return ans;
    }
};