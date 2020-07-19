class Solution {
public:
    pair<int, int> get(char aa, char bb, int cc) {
            int a1 = aa - '0', b1 = bb - '0';
            int sum = (a1 + b1 + cc) % 2;
            int carry = (a1 + b1 + cc) / 2;
            pair<int, int> ans = {sum, carry};
            return ans;
    }
    string addBinary(string a, string b) {
        reverse(a.begin(), a.end());
        reverse(b.begin(), b.end());
        const int N = 1e4 + 10;
        while ((int)a.size() < N) a.push_back('0');
        while ((int)b.size() < N) b.push_back('0');
        string ans = "";
        pair<int, int> gg;
        int cc = 0;
        for (int i = 0; i < N; i++) {
            gg = get(a[i], b[i], cc);
            ans.push_back(gg.first + '0');
            cc = gg.second;
        }
        while ((int)ans.size() > 1 && ans.back() == '0') ans.pop_back();
        reverse(ans.begin(), ans.end());
        return ans;
    }
};