class Solution {
public:
    string toLowerCase(string s) {
        for (auto& c : s) {
            if (c >= 65 && c <= 90 ) c = c - 'A' + 97;
        }
        return s;
    }
};