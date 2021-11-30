class Solution {
public:
    string convertToTitle(int n) {
        string str;
        const int N = 26;
        int r;
        while (n) {
            r = n % N;
            if (!r) str += 'Z';
            else str += ('A' + r - 1);
            n = (n - 1) / N;
        }
        reverse(str.begin(), str.end());
        return str;
    }
};