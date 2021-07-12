class Solution {
public:
    bool isIsomorphic(string s, string t) {
        unordered_map<char, char> mp;
        unordered_map<char, bool> ump;
        for (int i = 0; i < s.size(); i++) {
            if (mp.count(s[i]) && mp[s[i]] == t[i]) continue;
            if (!mp.count(s[i]) && !ump.count(t[i])) {
                mp[s[i]] = t[i];
                ump[t[i]] = true;
            } else return false;
        }
        return true;
    }
};