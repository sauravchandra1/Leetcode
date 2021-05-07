/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> neighbors;
    
    Node() {
        val = 0;
        neighbors = vector<Node*>();
    }
    
    Node(int _val) {
        val = _val;
        neighbors = vector<Node*>();
    }
    
    Node(int _val, vector<Node*> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
};
*/

class Solution {
public:
    Node* cloneGraph(Node* node) {
        unordered_map<int, Node*> mp;
        function<Node*(Node*)> dfs = [&](Node* node) {
            if (node == 0) return node;
            Node* curr = new Node(node->val);
            mp[node->val] = curr;
            for (int i = 0; i < node->neighbors.size(); i++) {
                auto C = node->neighbors;
                if (mp.count(C[i]->val) > 0) 
                    curr->neighbors.push_back(mp[C[i]->val]);
                else 
                    curr->neighbors.push_back(dfs(C[i]));
            }
            return curr;
        };
        return dfs(node);
    }
};