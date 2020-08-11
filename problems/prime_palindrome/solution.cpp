class Solution {
public:
    int primePalindrome(int N) {
        function<bool(int)> is_palin = [&](int n) {
            string str = to_string(n);
            int len = str.size();
            for (int i = 0; i < len / 2; i++) if (str[i] != str[len - i - 1]) return false;
            return true;
        };
        if (N <= 2) return 2;
        const int inf = INT_MAX;
        while (N < inf) {
            if (N % 2 == 0) N++;
            if (10000000 < N && N < 100000000) N = 100000000;
            bool ok = true;
            if (!is_palin(N)) {
                N += 2;
                continue;
            }
            for (int i = 3; i <= sqrt(N); i += 2) {
                if (N % i == 0) {
                    ok = false;
                    break;
                }
            }
            if (ok) return N;
            N += 2;
        }
        return 0;
    }
};