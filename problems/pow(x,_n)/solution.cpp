class Solution {
public:
    double myPow(double x, int n) {
        long long _n = n;
        double res = 1.0;
        bool neg = false;
        if (_n < 0) neg = true;
        _n = abs(_n);
        if (neg && x >= 1.9 && _n >= 11) {
            return 0.0000; 
        }
        while (_n > 0) {
            if (_n & 1) {
                res = res * x;
            }
            _n = _n >> 1;
            x = x * x;
        }
        if (neg) return 1.0 / res; else return res;
    }
};