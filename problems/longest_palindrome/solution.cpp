class Solution {
public:
    int longestPalindrome(string s) {
        unordered_map<char, int> mp;
        for (auto &v : s) {
            if (v >= 'A') {
                v = (v - 'A') + 'a';
            }
            mp[v]++;
        }
        bool ok = false;
        int ans = 0;
        for (auto v : mp) {
            if (v.second & 1) {
                ok = true;
                v.second--;
            }
            ans += v.second;
        }
        if (ok) {
            ans++;
        }
        return ans;
    }
};