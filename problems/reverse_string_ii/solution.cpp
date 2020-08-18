class Solution {
public:
    string reverseStr(string s, int k) {
        for (int i = 0, step = 2 * k, len = s.size(); i < len; i += step) reverse(begin(s) + i, begin(s) + min(i + k, len));
        return s;
    }
};