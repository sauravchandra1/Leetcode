class Solution {
public:
    string longestPalindrome(string s) {
        int n = s.size();
        auto make = [&](int i, int j) {
            tuple<int, int, int> res{1, 0, 0};
            while (i >= 0 && j < n) {
                if (s[i] == s[j]) {
                    i--, j++;
                } else break;
            }
            get<0>(res) = j - i - 1;
            get<1>(res) = i + 1;
            get<2>(res) = j - 1;
            return res;
        };
        tuple<int, int, int> res{1, 0, 0};
        for (int i = 1; i < n; i++) {
            tuple a = make(i - 1, i);
            tuple b = make(i - 1, i + 1);
            if (get<0>(a) > get<0>(res) && get<0>(a) > get<0>(b)) {
                res = a;
            } else if (get<0>(b) > get<0>(res) && get<0>(b) > get<0>(a)) {
                res = b;
            }
        }
        return s.substr(get<1>(res), get<0>(res));
    }
};