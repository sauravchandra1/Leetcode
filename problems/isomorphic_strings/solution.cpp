class Solution {
public:
    bool isIsomorphic(string s, string t) {
        unordered_map<char, char> mp, seen;
        int i = 0;
        for (auto v : s) {
            if (mp.count(v) == 0) {
                if (seen.count(t[i]) > 0) return false;
                mp[v] = t[i];
                seen[t[i]] = '*';
            } else if (mp[v] != t[i]) return false;
            i++;
        }
        return true;
    }
};