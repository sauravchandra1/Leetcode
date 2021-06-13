const int N = 26;

class TrieNode {
public:    
    vector<int> ind;
    TrieNode* next[N];
    TrieNode() { for (int i = 0; i < N; i++) next[i] = 0; }
};

class Trie {
public:
    TrieNode* root;
    Trie() { root = new TrieNode(); }
    void insert(string str, int i) {
        TrieNode* curr = root;
        for (auto c : str) {
            c = c - 'a';
            if (!curr->next[c])
                curr->next[c] = new TrieNode();
            curr = curr->next[c];
        }
        curr->ind.push_back(i);
    }
    vector<int> search(string str, int l, int r) {
        TrieNode* curr = root;
        char c;
        for (int i = r; i >= l; i--) {
            c = str[i] - 'a';
            if (!curr->next[c]) return {};
            curr = curr->next[c];
        }
        return curr->ind;
    }
};

class Solution {
public:
    bool isPalin(string str, int l, int r) {
        while (l < r) {
            if (str[l] != str[r]) return false;
            l++, r--;
        }
        return true;
    }
    vector<vector<int>> palindromePairs(vector<string>& words) {
        int len = words.size();
        Trie T;
        for (int i = 0; i < len; i++) T.insert(words[i], i);
        int idx = 0;
        set<vector<int>> ans;
        for (auto& w : words) {
            if (!w.size()) { idx++; continue; };
            for (int i = 0; i <= w.size(); i++) {
                if (isPalin(w, i, w.size() - 1)) {
                    auto vec = T.search(w, 0, i - 1);
                    for (auto& v : vec) if (v != idx) ans.insert({idx, v});
                }
                if (isPalin(w, 0, i - 1)) {
                    auto vec = T.search(w, i, w.size() - 1);
                    for (auto& v : vec) if (v != idx) ans.insert({v, idx});
                }
            }
            idx++;
        }
        return vector<vector<int>>(ans.begin(), ans.end());
    }
};