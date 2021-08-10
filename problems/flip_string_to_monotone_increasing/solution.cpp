class Solution {
public:
    int minFlipsMonoIncr(string s) {
        int n = s.size();
        vector<int> prefix(n + 1);
        for (int i = 0; i < n; i++) prefix[i + 1] = prefix[i] + (s[i] - '0');
        int ans = min(prefix[n], n - prefix[n]);
        for (int i = 0; i < n - 1; i++) 
            ans = min(ans, prefix[i + 1] + n - i - 1 - prefix[n] + prefix[i + 1]);
        return ans;
    }
};