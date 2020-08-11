class Solution {
private: 
    struct Node {
        array<Node*, 26> children;
        bool is_word = false;;
        string word = "";
    }; 
    Node* root = new Node();
    void insert(string& w) {
        Node* ptr = root;
        for (auto c : w) {
            if (!ptr->children[c - 'a']) ptr->children[c - 'a'] = new Node();
            ptr = ptr->children[c - 'a'];
        }
        ptr->word = w;
        ptr->is_word = true;
    }
    bool search(Node* ptr, char c, set<string>& res) {
        if (!ptr->children[c - 'a']) return false;
        ptr = ptr->children[c - 'a'];
        if (ptr->is_word) res.insert(ptr->word);
        return true;
    }
public:
    vector<string> findWords(vector<vector<char>>& board, vector<string>& words) {
        vector<string> ans;
        vector<int> dx {0, 1, 0, -1};
        vector<int> dy {1, 0, -1, 0};
        int r = board.size();
        if (!r) return ans;
        int c = board[0].size();
        auto get = [&](int x, int y) {
            if (x < 0 || y < 0 || x == r || y == c) return false;
            else return true;
        };
        for (auto& v : words) insert(v);
        set<string> res;
        function<bool(Node*, int, int)> dfs = [&](Node* ptr, int i, int j) {
            if (!ptr) return false;
            if (!get(i, j)) return false;
            if (board[i][j] == '*') return false;
            if (search(ptr, board[i][j], res)) {
                char c = board[i][j];
                ptr = ptr->children[c - 'a'];
                board[i][j] = '*';
                for (int d = 0; d < 4; d++) {
                    int x = i + dx[d];
                    int y = j + dy[d];
                    if (dfs(ptr, x, y)) return true;
                }
                board[i][j] = c;
            }
            return false;
        };
        for (int i = 0; i < r; i++) {
            for (int j = 0; j < c; j++) {
                dfs(root, i, j);
            }
        }
        for (auto v : res) ans.push_back(v);
        return ans;
    }
};