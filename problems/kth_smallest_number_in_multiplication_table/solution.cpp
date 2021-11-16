class Solution {
public:
    int findKthNumber(int m, int n, int k) {
        auto get = [&](int x) {
            int c = 0;
            for (int i = 1; i <= m; i++) c += min(x / i, n);
            return c;
        };
        int l = 1, r = m * n;
        while (l < r) {
            int mid = l + (r - l) / 2;
            int v = get(mid);
            if (v < k) l = mid + 1;
            else r = mid;
        }
        return l;
    }
};