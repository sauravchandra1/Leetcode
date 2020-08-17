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
    unordered_map < Node * , int > vis;
    unordered_map < Node * , Node * > track;
    void recur(Node * node, Node * ans, Node * par) {

        ans -> val = node -> val;
        vis[node] = 1;
        for (auto it: node -> neighbors) {
            if (vis[it] == 0) 
            {
                Node * temp = new Node(it -> val);
                track[it] = temp;
                ans -> neighbors.push_back(temp);
                recur(it, temp, node);
            } else if (vis[it] == 1) {
                Node * temp = track[it];
                ans -> neighbors.push_back(temp);
            }
        }
    }
    Node * cloneGraph(Node * node) {
        if (node == NULL)
            return NULL;
        Node * ans = new Node();
        track[node] = ans;
        Node * par = new Node();
        recur(node, ans, par);
        return ans;
    }
};