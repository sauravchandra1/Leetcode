class Solution {
public:
    string reverseWords(string s) {
        int i = 0;
        vector<string> vec;
        while (i < s.size()) {
            string ans;
            while (i < s.size() && s[i] != ' ') ans += s[i], i++;
            i++;
            if (ans.size() > 0) vec.push_back(ans);
        }
        string ans;
        for (int i = vec.size() - 1; i >= 0; i--) {
            ans += vec[i];
            if (i > 0) ans += ' ';
        }
        return ans;
    }
};