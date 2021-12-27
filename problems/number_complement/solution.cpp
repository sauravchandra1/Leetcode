class Solution {
public:
    int findComplement(int num) {
        int cnt = 0, n = num;
        while (n) {
            cnt++;
            n = n >> 1;
        }
        return (~num) & ((1LL << cnt) - 1);
    }
};