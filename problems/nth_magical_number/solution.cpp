class Solution {
public:
    long long gcd(int a, int b) {
        if (b == 0) return a;
        return gcd(b, a % b);
    }
    
    int nthMagicalNumber(int n, long long a, long long b) {
        long long lcm = (a * b) / gcd(a, b);
        long long mod = 1e9 + 7;
        long long l = 0, r = 4e13, m, t;
        auto get = [&](long long x) {
            return (x / a) + (x / b) - (x / lcm);
        };
        while (l < r) {
            m = (l + r) / 2LL;
            t = get(m);
            if (t > n) r = m - 1;
            else if (t < n) l = m + 1;
            else {
                return (m - min(m % a, m % b)) % mod;
            }
        }
        return l % mod;
    }
};