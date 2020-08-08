class Solution {
public:
    vector<string> findAllConcatenatedWordsInADict(vector<string>& words) {
        unordered_map<string, bool> ump;
        vector<string> ans;
        for (auto v : words) if (v != "") ump[v] = true;
        function<bool(string)> dfs = [&](string str) {
            if (str == "") return false;
            if (ump.count(str) > 0) return true;
            string curr;
            bool res = false;
            for (int i = 0; i < str.size() - 1; i++) {
                curr += str[i];
                if (ump.count(curr) > 0) res = dfs(str.substr(i + 1));
                if (res) return true;
            }
            return res;
        };
        for (auto v : words) {
            if (v.size() == 0) continue;
            string curr = "";
            bool res = false;
            for (int i = 0; i < v.size() - 1; i++) {
                curr += v[i];
                if (ump.count(curr) > 0) res = dfs(v.substr(i + 1));
                if (res) {
                    ans.push_back(v);
                    break;
                }
            }
        }
        return ans;
    }
};