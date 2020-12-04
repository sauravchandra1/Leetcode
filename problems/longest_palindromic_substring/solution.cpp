class Solution {
public:
    string longestPalindrome(string s) {
        int len = s.size();
        string ans;
        if (len == 0) return ans;
        if (len == 1) return s;
        const int inf = 1e4;
        int _max1 = -inf, _l1, _r1;
        // Check if the longest substring have a center character
        for (int i = 0; i < len; i++) {
            int l = i - 1, r = i + 1;
            while (l >= 0 && r < len && s[l] == s[r]) {
                l--, r++;
            }
            l++, r--;
            if ((r - l + 1) > _max1) {
                _max1 = r - l + 1;
                _l1 = l;
                _r1 = r;
            }
        }
        int _max2 = -inf, _l2, _r2;
        // Check if the longest substring have two same charaters in center
        for (int i = 0; i < len; i++) {
            if (i + 1 < len && s[i] == s[i + 1]) {
                int l = i - 1, r = i + 2;
                while (l >= 0 && r < len && s[l] == s[r]) {
                    l--, r++;
                }
                l++, r--;
                if ((r - l + 1) > _max2) {
                    _max2 = r - l + 1;
                    _l2 = l;
                    _r2 = r;
                }
            }
        }
        int l, r;
        if (_max1 > _max2) {
            l = _l1;
            r = _r1;
        } else {
            l = _l2;
            r = _r2;
        }
        for (int i = l; i <= r; i++) {
            ans += s[i];
        }
        return ans;
    }
};