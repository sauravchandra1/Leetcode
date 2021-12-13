class Solution {
public:
    int maxPower(string s) {
        int ans = 1, _max = 1;
        char last = s[0];
        for (int i = 1; i < s.size(); i++) {
            if (s[i] == last) ans++;
            else {
                if (ans > _max) _max = ans;
                ans = 1;
                last = s[i];
            }
        }
        return max(ans, _max);
    }
};