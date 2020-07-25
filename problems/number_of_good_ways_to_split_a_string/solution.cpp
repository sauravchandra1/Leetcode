class Solution {
public:
    int numSplits(string s) {
        set<char> stf, str;
        int n = s.size();
        vector<int> vecf(n, 0), vecr(n, 0);
        for (int i = 0; i < n; i++) {
            stf.insert(s[i]);
            vecf[i] = stf.size();
        }
        for (int i = n - 1; i >= 0; i--) {
            str.insert(s[i]);
            vecr[i] = str.size();
        }
        int ans = 0;
        for (int i = 0; i < n - 1; i++) {
            if (vecf[i] == vecr[i + 1]) ans++;
        }
        return ans;
    }
};