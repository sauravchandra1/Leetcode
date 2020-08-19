class Solution {
public:
    string reverseVowels(string s) {
        string str;
        unordered_map<char, bool> mp;
        mp['a'] = true;
        mp['e'] = true;
        mp['i'] = true;
        mp['o'] = true;
        mp['u'] = true;
        mp['A'] = true;
        mp['E'] = true;
        mp['I'] = true;
        mp['O'] = true;
        mp['U'] = true;
        for (auto &v: s) {
            if (mp[v] == true) {
                str += v;
                v = '*';
            }
        }
        reverse(str.begin(), str.end());
        int i = 0;
        for (auto &v : s) {
            if (v == '*') {
                v = str[i++];
            }
        }
        return s;
    }
};