class Solution {
public:
    string longestDupSubstring(string S) {
        const long long mod = 1e9 + 7;
        const long long N = 26;
        string ans;
        int len = S.size();
        vector<long long> p(len);
        p[0] = 1;
        for (int i = 1; i < len; i++) p[i] = (p[i - 1] * N) % mod;
        int res = 0;
        function<bool(int)> get = [&](int l) {
            if (l == 0) return true;
            if (l == len) return false;
            unordered_map<int, vector<int>> mp;
            int j = 0;
            long long hash = 0, last = (p[l - 1] * (S[j++] - 'a') * 1LL) % mod;
            for (int i = 0; i < l; i++) 
                hash = (hash + p[i] * (S[l - i - 1] - 'a') * 1LL) % mod;
            mp[hash].push_back(0);
            for (int i = l; i < len; i++) {
                hash -= last;
                hash += mod;
                hash *= N;
                hash %= mod;
                if (hash < 0) while(1);
                hash = (hash + (S[i] - 'a')) % mod;
                last = (p[l - 1] * (S[j++] - 'a') * 1LL) % mod;
                if (mp.find(hash) != mp.end()) {
                    for (auto v : mp[hash]) {
                        if (S.substr(i - l + 1, l) == S.substr(v, l)) {
                            res = i - l + 1;
                            return true;
                        }
                    }
                }
                mp[hash].push_back(i - l + 1);
            }
            return false;
        };
        int l = 0, r = len, mid;
        while (l < r) {
            mid = (l + r + 1) / 2;
            if (get(mid)) l = mid;
            else r = mid - 1;
        }
        if (l == 0) return ans;
        return S.substr(res, l);
    }
};