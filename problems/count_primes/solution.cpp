class Solution {
public:
    int countPrimes(int n) {
       vector<bool> prime(n, true);
        if (n == 0) return 0;
        prime[0] = prime[1] = false;
        int ans = 0;
        for (long long int i = 2; i < n; i++) {
            if (prime[i]) {
                ans++;
                for (long long int j = i * i; j < n; j += i) {
                    prime[j] = false;
                }   
            }
        }
        return ans;
    }
};