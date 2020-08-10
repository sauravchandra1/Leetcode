class Solution {
public:
    vector<vector<string>> findLadders(string beginWord, string endWord, vector<string>& wordList) {
        unordered_set<string> wl(wordList.begin(), wordList.end());
        unordered_set<string> seen;
        queue<vector<string>> Q;
        vector<vector<string>> ans;
        Q.push({beginWord});
        int k = 0;
        bool ok = false;
        string last, tt;
        vector<string> new_path;
        while (!Q.empty()) {
            if (ok) break;
            for (auto v : seen) wl.erase(v);
            int k = Q.size();
            while (k--) {
                new_path = Q.front();
                Q.pop();
                last = new_path.back();
                if (last == endWord) {
                    ok = true;
                    ans.push_back(new_path);
                }
                if (ok) continue;
                tt = last;
                for (int i = 0; i < last.size(); i++) {
                    for (int j = 0; j < 26; j++) {
                        last[i] = j + 'a';
                        if (wl.find(last) != wl.end()) {
                            seen.insert(last);
                            new_path.push_back(last);
                            Q.push(new_path);
                            new_path.pop_back();
                        }
                    }
                    last[i] = tt[i];
                }
            }
        }
        return ans;
    }
};