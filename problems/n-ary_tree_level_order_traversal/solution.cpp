/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> children;

    Node() {}

    Node(int _val) {
        val = _val;
    }

    Node(int _val, vector<Node*> _children) {
        val = _val;
        children = _children;
    }
};
*/

class Solution {
public:
    vector<vector<int>> levelOrder(Node* root) {
        vector<vector<int>> ans;
        if (root == 0) return ans;
        queue<Node*> Q;
        Q.push(root);
        while (!Q.empty()) {
            int len = Q.size();
            vector<int> vec;
            for (int i = 0; i < len; i++) {
                Node* curr = Q.front();
                Q.pop();
                vec.push_back(curr->val);
                for (Node* c : curr->children) Q.push(c);
            }
            ans.push_back(vec);
        }
        return ans;
    }
};