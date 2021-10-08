class TrieNode {
    public final int N = 26;
    public TrieNode next[];
    public boolean isLast;
    
    public TrieNode() {
        next = new TrieNode[N];
        for (int i = 0; i < N; i++)
            next[i] = null;
        isLast = false;
    }
    
}
class Trie {
    public TrieNode root, curr;
    public Trie() {
        root = new TrieNode();
    }
    
    public void insert(String word) {
        curr = root;
        int idx = 0;
        for (int i = 0; i < word.length(); i++) {
            idx = word.charAt(i) - 'a';
            if (curr.next[idx] == null) 
                curr.next[idx] = new TrieNode();
            curr = curr.next[idx];
        }
        curr.isLast = true;
    }
    
    public boolean search(String word) {
        curr = root;
        int idx;
        for (int i = 0; i < word.length(); i++) {
            idx = word.charAt(i) - 'a';
            if (curr.next[idx] == null) return false;
            curr = curr.next[idx];
        }
        return curr.isLast;
    }
    
    public boolean startsWith(String prefix) {
        curr = root;
        int idx;
        for (int i = 0; i < prefix.length(); i++) {
            idx = prefix.charAt(i) - 'a';
            if (curr.next[idx] == null) return false;
            curr = curr.next[idx];
        }
        return true;
    }
}

/**
 * Your Trie object will be instantiated and called as such:
 * Trie obj = new Trie();
 * obj.insert(word);
 * boolean param_2 = obj.search(word);
 * boolean param_3 = obj.startsWith(prefix);
 */