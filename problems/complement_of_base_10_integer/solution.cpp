class Solution {
public:
    int bitwiseComplement(int n) {
        if (n == 0) return 1;
        int cnt = 0, num = n;
        while (n) {
            cnt++;
            n = n >> 1;
        }
        return (~num) & ((1LL << cnt) - 1);
    }
};