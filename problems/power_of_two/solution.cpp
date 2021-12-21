class Solution {
public:
    bool isPowerOfTwo(int n) {
        if (n <= 0) return false;
        int cnt = 0;
        while (n) {
            if (n & 1) cnt++;
            if (cnt > 1) return false;
            n /= 2;
        }
        return true;
    }
};