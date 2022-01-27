const int N = 32;

class TrieNode {
public:
    TrieNode* next[2]; 
    TrieNode() {
        next[0] = next[1] = 0;
    }    
};

class Trie {
    TrieNode* root;
public:
    Trie() {
        root = new TrieNode();
    }
    void insert(int x) {
        bitset<N> b(x);
        TrieNode* curr = root;
        for (int i = N; i >= 0; i--) {
            if (!curr->next[b[i]])
                curr->next[b[i]] = new TrieNode();
            curr = curr->next[b[i]];
        }
    }
    int get(int x) {
        bitset<N> b(x);
        int ans = 0;
        TrieNode* curr = root;
        for (int i = N; i >= 0; i--) {
            if (!curr->next[!b[i]])
                curr = curr->next[b[i]];
            else {
                curr = curr->next[!b[i]];
                ans |= (1 << i);
            }
        }
        return ans;
    }
};

class Solution {
public:
    int findMaximumXOR(vector<int>& nums) {
        Trie T;
        for (auto& v : nums) 
            T.insert(v);
        int res = 0;
        for (auto& v : nums)
            res = max(res, T.get(v));
        return res;
    }
};