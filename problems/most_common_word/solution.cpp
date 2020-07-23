class Solution {
public:
    string mostCommonWord(string paragraph, vector<string>& banned) {
        string ans = "";
        map<string, int> res;
        map<string, bool> check;
        for (auto v : banned) check[v] = true;
        for (int i = 0; i < paragraph.size(); i++) {
            char ch = paragraph[i];
            if (ch >= 'A' && ch <= 'Z') ch = 'a' + (ch - 'A');
            if (ch >= 'a' && ch <= 'z') ans += ch;
            else {
                if (ans == "") continue;
                if (check.count(ans) == 0) res[ans]++;
                ans = "";
            }
            if (i == paragraph.size() - 1) {
                if (ans == "") continue;
                if (check.count(ans) == 0) res[ans]++;
                ans = "";
            }
        }
        int _max = 0;
        for (auto v : res) {
            if (v.second > _max) {
                _max = v.second;
                ans = v.first;
            }
        }
        return ans;
    }
};