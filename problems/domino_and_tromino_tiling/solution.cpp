class Solution {
public:
    int numTilings(int n) {
        if (n <= 2) return n;
        const int N = 3;
        const int mod = 1e9 + 7;
        int arr[N];
        arr[0] = 1, arr[1] = 1, arr[2] = 2;
        for (int i = 3; i <= n; i++) {
            arr[i % N] = (arr[(i - 1) % N] * 2) % mod + arr[(i - 3) % N] % mod;
            arr[i % N] %= mod;
        }
        return arr[n % N];
    }
};