class Solution {
public:
    string customSortString(string order, string str) {
        const int N = 26;
        vector<int> cnt(N, 0);
        for (int i = 0; i < str.size(); i++) cnt[str[i] - 'a']++;
        string ans;
        for (auto& v : order) 
            while (cnt[v - 'a']) {
                ans += v;
                cnt[v - 'a']--;
            }
        for (int i = 0; i < N; i++) 
            while (cnt[i]) {
                ans += i + 'a';
                cnt[i]--;
            }
        return ans;
    }
};