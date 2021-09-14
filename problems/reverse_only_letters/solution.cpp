class Solution {
public:
    string reverseOnlyLetters(string s) {
        auto get = [&](int i) {
            if (s[i] >= 'a' && s[i] <= 'z') return true;
            if (s[i] >= 'A' && s[i] <= 'Z') return true;
            return false;
        };
        int l = 0, r = s.size() - 1; 
        while (l < r) {
            if (!get(l)) {
                l++;
                continue;
            } else if (!get(r)) {
                r--;
                continue;
            }
            swap(s[l], s[r]);
            l++, r--;
        }
        return s;
    }
};