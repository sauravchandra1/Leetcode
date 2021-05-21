class Solution {
public:
    vector<string> findAndReplacePattern(vector<string>& words, string pattern) {
        unordered_map<char, char> mp;
        int count;
        vector<string> cpy(words);
        auto get = [&](string& w) {
            count = 0;
            mp.clear();
            for (auto& c : w) {
                if (mp.find(c) != mp.end()) c = mp[c];
                else {
                    mp[c] = count + '0';
                    c = mp[c];
                    count++;
                }
            }
        };
        for (auto& w : words) get(w);
        get(pattern);
        vector<string> ans;
        for (int i = 0; i < words.size(); i++) if (pattern == words[i]) ans.push_back(cpy[i]);
        return ans;
    }
};