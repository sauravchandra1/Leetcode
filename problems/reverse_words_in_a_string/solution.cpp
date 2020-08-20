class Solution {
public:
    string reverseWords(string s) {
        while (s.size() && s.back() == ' ') {
            s.pop_back();
        }
        function<void(int, int)> rev = [&](int l, int r) {
            int len = r - l + 1;
            for (int i = 0; i < len / 2; i++) {
                swap(s[i + l], s[r - i]);
            }
        };
        rev(0, s.size() - 1);
        char v;
        int l;
        for (int i = 0; i < s.size(); i++) {
            v = s[i];
            if (v != ' ') {
                l = i;
                while (i + 1 < s.size() && s[i + 1] != ' ') {
                    i++;
                }
                rev(l, i);
            } else {
                while (i + 1 < s.size() && s[i + 1] == ' ') {
                    s.erase(s.begin() + i + 1);
                }
            }
        }
        while (s.size() && s.back() == ' ') {
            s.pop_back();
        }
        return s;
    }
};