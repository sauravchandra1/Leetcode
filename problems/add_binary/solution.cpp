class Solution {
public:
    string addBinary(string a, string b) {
        int i = a.size() - 1, j = b.size() - 1, c = 0, s;
        string ans;
        while (i >= 0 || j >= 0) {
            s = c;
            if (i >= 0) s += a[i] - '0';
            if (j >= 0) s += b[j] - '0';
            c = s / 2;
            ans += ((s % 2) + '0'); 
            i--, j--;
        }
        if (c) ans += '1';
        reverse(ans.begin(), ans.end());
        return ans;
    }
};