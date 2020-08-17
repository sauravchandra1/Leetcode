class Solution {
public:
    vector < vector < int >> res;

    struct TrieNode {
        int indexWord;
        bool isWord;
        TrieNode * children[26];
    };

    TrieNode * getNewNode() {
        TrieNode * node = new TrieNode();
        node -> isWord = false;
        node -> indexWord = -1;
        for (int i = 0; i < 26; i++)
            node -> children[i] = NULL;
        return node;
    }

    void insert(TrieNode * root, string & word, int indexWord) {
        TrieNode * temp = root;
        for (int i = 0; i < word.length(); i++) {
            int index = word[i] - 'a';
            if (temp -> children[index] == NULL)
                temp -> children[index] = getNewNode();
            temp = temp -> children[index];
        }
        temp -> isWord = true;
        temp -> indexWord = indexWord;
    }

    bool isSubstringPalindrone(string str) {
        string s1 = str;
        reverse(str.begin(), str.end());
        return s1 == str;
    }

    void dfs(TrieNode * root, vector < int > & v1, string & str) {
        if (root == NULL)
            return;
        if (root -> isWord == true && str != "" && isSubstringPalindrone(str))
            v1.push_back(root -> indexWord);
        for (int i = 0; i < 26; i++) {
            if (root -> children[i] != NULL) {
                str += 'a' + i;
                dfs(root -> children[i], v1, str);
                str.pop_back();
            }
        }
    }

    void helper(TrieNode * root, string word, int wordIndex) {
        int index = 0;
        while (index < word.length()) {
            root = root -> children[word[index] - 'a'];
            index++;
            if (root == NULL)
                break;
            if (root -> isWord == true) {
                if (root -> indexWord != wordIndex && isSubstringPalindrone(word.substr(index))) {
                    vector < int > v1;
                    v1.push_back(wordIndex);
                    v1.push_back(root -> indexWord);
                    res.push_back(v1);
                }
            }
        }
        if (index == word.length() && root != NULL) {
            string str = "";
            vector < int > v1;
            dfs(root, v1, str);
            for (int i: v1) {
                if (i != wordIndex) {
                    vector < int > v2;
                    v2.push_back(wordIndex);
                    v2.push_back(i);
                    res.push_back(v2);
                }
            }
        }

    }

    vector < vector < int >> palindromePairs(vector < string > & words) {
        TrieNode * root = getNewNode();
        int emptyIndex = -1;
        for (int i = 0; i < words.size(); i++) {
            if (words[i] == "")
                emptyIndex = i;
            string word = words[i];
            reverse(word.begin(), word.end());
            insert(root, word, i);
        }

        for (int i = 0; i < words.size(); i++) {
            string word = words[i];
            if (emptyIndex != -1 && i != emptyIndex && isSubstringPalindrone(word)) {
                vector < int > v1;
                v1.push_back(i);
                v1.push_back(emptyIndex);
                res.push_back(v1);
            }
            helper(root, word, i);
        }

        return res;
    }
};