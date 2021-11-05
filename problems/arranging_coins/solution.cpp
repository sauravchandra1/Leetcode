class Solution {
public:
    int arrangeCoins(int n) {
        long long t = (1LL + 8LL * n);
        return (sqrt(t) - 1LL) / 2LL;
    }
};