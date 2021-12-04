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
    TrieNode* root;
public:
    Trie() {
        root = new TrieNode();
    }
    void insert(string &str) {
        TrieNode* curr = root;
        char v;
        for (int i = str.size() - 1; i >= 0; i--) {
            v = str[i];
            if (!curr->next[v - 'a']) curr->next[v - 'a'] = new TrieNode();
            curr = curr->next[v - 'a'];
        }
        curr->isLast = true;
    }
    bool find(string& str) {
        TrieNode* curr = root;
        for (int i = str.size() - 1; i >= 0; i--) {
            if (!curr->next[str[i] - 'a']) 
                return false;
            curr = curr->next[str[i] - 'a'];
            if (curr->isLast) return true;
        }
        return curr->isLast;
    }
};

class StreamChecker {
public:
    Trie T;
    string str;
    StreamChecker(vector<string>& words) {
        for (auto& v : words) T.insert(v);
    }
    
    bool query(char letter) {
        str += letter;
        return T.find(str);
    }
};

/**
 * Your StreamChecker object will be instantiated and called as such:
 * StreamChecker* obj = new StreamChecker(words);
 * bool param_1 = obj->query(letter);
 */