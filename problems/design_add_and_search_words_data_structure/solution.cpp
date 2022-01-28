const int N = 26;
class TrieNode {
public:
    TrieNode* next[N];    
    bool isLast;
    TrieNode() {
        for (int i = 0; i < N; i++) 
            next[i] = 0;
        isLast = false;
    }
};

class Trie {
public:
    TrieNode* root;
    Trie() {
        root = new TrieNode();
    }
    
    void insert(string str) {
        TrieNode* curr = root;
        int v;
        for (auto& c : str) {
            v = c - 'a';
            if (!curr->next[v])
                curr->next[v] = new TrieNode();
            curr = curr->next[v];
        }
        curr->isLast = true;
    }
    
    bool find(string& str, int idx, TrieNode* curr) {
        if (idx == str.size()) return curr->isLast;
        bool res = false;
        if (str[idx] == '.') {
            for (int i = 0; i < N; i++) {
                if (curr->next[i])
                    res = res || find(str, idx + 1, curr->next[i]);
            }
        } else {
            if (!curr->next[str[idx] - 'a']) 
                return false;
            res = find(str, idx + 1, curr->next[str[idx] - 'a']);
        }
        return res;
    }
};

class WordDictionary {
    Trie T;
public:
    WordDictionary() {
        
    }
    
    void addWord(string word) {
        T.insert(word);
    }
    
    bool search(string word) {
        return T.find(word, 0, T.root);
    }
};

/**
 * Your WordDictionary object will be instantiated and called as such:
 * WordDictionary* obj = new WordDictionary();
 * obj->addWord(word);
 * bool param_2 = obj->search(word);
 */