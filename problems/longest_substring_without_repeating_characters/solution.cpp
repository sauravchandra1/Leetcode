class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int len = s.size();
        int ans = 0, idx = 0, _max = 0;
        vector<bool> seen(128, false);
        for (int i = 0; i < len; i++) {
            int v = (int)s[i];
            while (seen[v] == true) {
                int p = (int)s[idx];
                seen[p] = false;
                ans--;
                idx++;
            }
            seen[v] = true;
            ans++;
            _max = max(_max, ans);
        }
        return _max;
    }
};