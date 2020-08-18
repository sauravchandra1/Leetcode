class Solution {
    public:

        bool isAnagram(unordered_map < char, int > a, unordered_map < char, int > b) {
            if (a.size() != b.size()) return false;
            for (auto c: a) {
                if (b[c.first] > 0) {
                    if (b[c.first] != c.second) return false;
                } else return false;
            }
            return true;
        }

    vector < int > findAnagrams(string s, string p) {
        int r = 0;
        unordered_map < char, int > a, b;
        for (r = 0; r < p.length(); ++r) {
            a[s[r]]++;
            b[p[r]]++;
        }

        r = 0;
        int lengthOfP = p.length();
        vector < int > indexes;
        while (r < s.length()) {
            if (isAnagram(a, b)) {
                indexes.push_back(r);
            }
            a[s[r]]--;
            if (a[s[r]] == 0) a.erase(s[r]);

            if (lengthOfP < s.length()) {
                a[s[lengthOfP]]++;
            }

            ++lengthOfP;
            ++r;
        }

        return indexes;
    }
};