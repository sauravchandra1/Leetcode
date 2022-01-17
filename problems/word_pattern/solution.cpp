class Solution {
public:
    bool wordPattern(string pattern, string s) {
        int idx = 0;
        auto next = [&]() {
            string res;
            while (idx < s.size() && s[idx] != ' ') {
                res += s[idx++];
            }
            idx++;
            return res;
        };
        unordered_map<char, string> mp;
        unordered_map<string, char> ump;
        for (auto c : pattern) {
            string curr = next();
            if (curr.size() == 0) return false;
            if (mp.count(c) == 0) {
                if (ump.count(curr)) return false;
                mp[c] = curr;
                ump[curr] = c;
            }
            else if (curr != mp[c]) return false;
        }
        if (idx < s.size()) return false;
        return true;
    }
};