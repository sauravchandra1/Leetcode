class Solution {
public:
    string minWindow(string s, string t) {
        const int N = 52;
        int n1 = s.size();
        int n2 = t.size();
        auto get = [](char c) {
            if (c >= 'A' && c <= 'Z') return (c - 'A');
            else return (26 + c - 'a');
        };
        vector<int> reel(N), real(N), temp(N);
        int cnt = n2;
        for (auto& v : t) {
            real[get(v)]++;
            temp[get(v)]++;
        }
        int i1 = 0, i2 = 0;
        int p = -1, q = 1e6;
        while (i2 < n1) {
            if (temp[get(s[i2])])
                cnt--, temp[get(s[i2])]--;
            reel[get(s[i2])]++;
            if (!cnt) {
                while (i1 < i2) {
                    if (reel[get(s[i1])] > real[get(s[i1])]) {
                        reel[get(s[i1])]--;
                        i1++;
                    } else break;
                }
                if ((i2 - i1) < (q - p)) 
                    p = i1, q = i2;
            }
            i2++;
        }
        string ans;
        if (p >= 0) ans = s.substr(p, q - p + 1);
        return ans;
    }
};