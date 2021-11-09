const int N = 26;
class TrieNode {
public:    
    TrieNode* next[N];
    int lastCount;
    TrieNode() {
        for (int i = 0; i < N; i++) next[i] = 0;
        lastCount = 0;
    }
};

class Trie {
    TrieNode* root;
public:
    Trie() { root = new TrieNode(); }
    void add(string str) {
        TrieNode* curr = root;
        for (auto& c : str) {
            int v = c - 'a';
            if (!curr->next[v]) curr->next[v] = new TrieNode();
            curr = curr->next[v];
        }
        curr->lastCount++;
    }
    int find(string str) {
        TrieNode* curr = root;
        for (auto& c : str) {
            int v = c - 'a';
            curr = curr->next[v];
            if (!curr) return 0;
        }
        return curr->lastCount;
    }
};

class Solution {
public:
    vector<int> findNumOfValidWords(vector<string>& words, vector<string>& puzzles) {
        Trie T;
        vector<bool> vec(N);
        for (auto& str : words) {
            for (int i = 0; i < N; i++) vec[i] = false;
            for (auto& c : str) vec[c - 'a'] = true;
            string s;
            for (int i = 0; i < N; i++) 
                if (vec[i]) s += i + 'a';
            T.add(s);
        }
        vector<int> res;
        for (auto& str : puzzles) {
            int ans = 0;
            char last = str[0];
            str.erase(str.begin());
            int len = str.size();
            for (int mask = 0; mask < (1 << len); mask++) {
                for (int i = 0; i < N; i++) vec[i] = false;
                vec[last - 'a'] = true;
                for (int i = 0; i < len; i++) 
                    if (mask & (1 << i)) vec[str[len - 1 - i] - 'a'] = true;
                string s;
                for (int i = 0; i < N; i++)
                    if (vec[i]) s += i + 'a';
                ans += T.find(s);
            }
            res.push_back(ans);
        }
        return res;
    }
};