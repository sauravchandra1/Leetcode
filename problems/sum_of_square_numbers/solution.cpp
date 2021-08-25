class Solution {
public:
    bool judgeSquareSum(int c) {
        auto isSquare = [](long long x) {
            long long n = sqrt(x);
            return (n * n == x ? true : false); 
        };
        int lim = sqrt(c / 2);
        for (long long i = 0; i <= lim; i++) 
            if (isSquare(c - i * i)) return true;
        return false;
    }
};