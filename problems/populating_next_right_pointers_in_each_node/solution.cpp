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
        if (root == 0) return root;
        queue<Node*> Q;
        Node* curr = 0, *next = 0;
        Q.push(root);
        while (!Q.empty()) {
            int len = Q.size();
            while (len--) {
                curr = Q.front();
                Q.pop();
                if (curr->left) {
                    Q.push(curr->left);
                    Q.push(curr->right);
                }
                if (len == 0) curr->next = 0;
                else curr->next = Q.front();
            }
        }
        return root;
    }
};