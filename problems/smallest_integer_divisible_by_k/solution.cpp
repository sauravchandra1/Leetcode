class Solution {
public:
    int smallestRepunitDivByK(int k) {
        if (k % 2 == 0) return -1;
        int ans = 1, n = 1;
        const int inf = 1e5;
        while (true) {
            if (ans > inf) return -1;
            while (n < k) {
                n = n * 10 + 1;
                ans++;
            }
            n = n % k;
            if (n == 0) return ans;
        }
        return -1;
    }
};