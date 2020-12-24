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
    void trav(Node* root) {
        if (root == NULL) return;
        if (root->left) root->left->next = root->right;
        Node* l = root->left;
        Node* r = root->right;
        if (l && r) {
            while (l->right && r->left) {
                l = l->right;
                r = r->left;
                l->next = r;
            }
            trav(root->left);
            trav(root->right);
        }
    }
    Node* connect(Node* root) {
        trav(root);
        return root;
    }
};