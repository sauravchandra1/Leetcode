/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* left;
    Node* right;
    Node* next;

    Node() : val(0), left(NULL), right(NULL), next(NULL) {}

    Node(int _val) : val(_val), left(NULL), right(NULL), next(NULL) {}

    Node(int _val, Node* _left, Node* _right, Node* _next)
        : val(_val), left(_left), right(_right), next(_next) {}
};
*/

class Solution {
public:
    Node* connect(Node* root) {
        const int N = 70;
        vector<vector<Node*>> ans(N);
        function<void(Node*, int d)> dfs = [&](Node* root, int d) {
            if (root == NULL) return;
            ans[d].push_back(root);
            dfs(root->left, d + 1);
            dfs(root->right, d + 1);
        };
        dfs(root, 0);
        for (int i = 0; i < N; i++) {
            int len = ans[i].size();
            for (int j = 0; j < len - 1; j++) {
                ans[i][j]->next = ans[i][j + 1];
            }
            if (len) {
                ans[i][len - 1]->next = NULL;
            }
        }
        return root;
    }
};