class Solution {
public:
    int tribonacci(int n) {
        int a[3] = {0, 1, 1};
        if (n <= 2) return a[n];
        int sum;
        for (int i = 3; i <= n; i++) {
            sum = a[0] + a[1] + a[2];
            a[0] = a[1];
            a[1] = a[2];
            a[2] = sum;
        }
        return sum;
    }
};