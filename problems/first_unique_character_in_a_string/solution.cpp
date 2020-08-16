class Solution {
public:
    int firstUniqChar(string s) {
        unordered_map<char, int> mp;
        int i = 0;
        for (auto v : s) {
            mp[v]++;
        }
        for (auto v : s) {
            if (mp[v] == 1) return i;
            i++;
        }
        return -1;
    }
};