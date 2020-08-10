class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        unordered_set<string> wl(wordList.begin(), wordList.end());
        unordered_set<string> seen;
        queue<pair<string, int>> Q;
        if (wl.find(endWord) == wl.end()) return 0;
        Q.push(make_pair(beginWord, 1));
        seen.insert(beginWord);
        string tt, curr_word;
        int curr_dist;
        while (!Q.empty()) {
            curr_word = Q.front().first;
            curr_dist = Q.front().second;
            Q.pop();
            tt = curr_word;
            for (int i = 0; i < tt.size(); i++) {
                for (int j = 0; j < 26; j++) {
                    tt[i] = j + 'a';
                    if (wl.find(tt) != wl.end() && seen.find(tt) == seen.end()) {
                        if (tt == endWord) return curr_dist + 1;
                        Q.push(make_pair(tt, curr_dist + 1));
                        seen.insert(tt);
                    }
                }
                tt[i] = curr_word[i];
            }
        }
        return 0;
    }
};