class Solution {
public:
    bool isPalindrome(string s) {
        string ans;
        for (auto v : s) {
            if (v >= 'A' && v <= 'Z') v = (v - 'A') + 'a';
            if (v >= 'a' && v <= 'z') ans += v;
            if (v >= '0' && v <= '9') ans += v;
        }
        string cpy = ans;
        reverse(cpy.begin(), cpy.end());
        if (ans == cpy) return true;
        else return false;
    }
};