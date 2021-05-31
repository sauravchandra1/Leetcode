const int N = 26;

class TrieNode {
public:
    TrieNode* next[N];
    bool isLast;
    TrieNode() {
        for (int i = 0; i < N; i++) next[i] = 0;
        isLast = false;
    }
};

class Trie {
public:
    TrieNode* root;
    Trie() { root = new TrieNode(); }
    void insert(string str) {
        TrieNode* curr = root;
        for (auto& c : str) {
            if (curr->next[c - 'a'] == 0) curr->next[c - 'a'] = new TrieNode();
            curr = curr->next[c - 'a'];
        }
        curr->isLast = true;
    }
    void findRec(TrieNode* curr, string res, vector<string>& ans) {
        if (curr == 0 || ans.size() == 3) return;
        if (curr->isLast) {
            ans.push_back(res);
            if (ans.size() == 3) return;
        }
        for (int j = 0; j < N; j++) {
            char c = 'a' + j;
            if (curr->next[j]) findRec(curr->next[j], res + c, ans);
        }
    }
    vector<string> find(string str) {
        TrieNode* curr = root;
        vector<string> ans;
        string res;
        for (auto& c : str) {
            res += c;
            curr = curr->next[c - 'a'];
            if (curr == 0) return ans;
        }
        findRec(curr, res, ans);
        return ans;
    }
};

class Solution {
public:
    vector<vector<string>> suggestedProducts(vector<string>& products, string searchWord) {
        Trie T;
        for (auto& v : products) T.insert(v);
        string str;
        vector<vector<string>> ans;
        for (auto& c : searchWord) {
            str += c;
            ans.push_back(T.find(str));
        }
        return ans;
    }
};