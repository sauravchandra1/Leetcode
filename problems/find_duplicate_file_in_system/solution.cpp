class Solution {
public:
    vector<vector<string>> findDuplicate(vector<string>& paths) {
        stringstream stream;
        string word, path;
        vector<vector<string>> vec, ans;
        unordered_map<string, vector<pair<string, string>>> mp;
        vector<string> temp;
        for (auto& v : paths) {
            stream.str(v);
            temp.clear();
            while (getline(stream, word, ' ')) temp.push_back(word);
            vec.push_back(temp);
            stream.clear();
        }
        for (auto& e : vec) {
            word = "";
            int l, r;
            for (int i = 1; i < e.size(); i++) {
                int idx = e[i].find("(");
                int len = e[i].size() - idx - 2;
                mp[e[i].substr(idx + 1, len)].push_back({e[0], e[i].substr(0, idx)});
            }
        }
        for (auto& v : mp) {
            if (v.second.size() > 1) {
                temp.clear();
                for (auto& e : v.second) temp.push_back(e.first + "/" + e.second);
                ans.push_back(temp);
            }
        }
        return ans;
    }
};