/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution {
public:
    Node* copyRandomList(Node* head) {
        Node* curr = head;
        Node* new_head = NULL;
        Node* prev = NULL;
        if (head == NULL) return NULL;
        int ind = 0;
        map<Node*, int> l1;
        map<int, Node*> l2;
        while (curr != NULL) {
            Node* temp = new Node(curr->val);
            if (ind == 0) {
                new_head = temp;
            } else {
                prev->next = temp;
            }
            l1[curr] = ind;
            l2[ind] = temp;
            prev = temp;
            curr = curr->next;
            ind++;
        }
        curr = head;
        prev = new_head;
        while (curr != NULL) {
            if (curr->random == NULL) {
                curr = curr->next;
                prev = prev->next;
                continue;
            }
            int idx = l1[curr->random];
            Node* p = l2[idx];
            prev->random = p;
            curr = curr->next;
            prev = prev->next;
        }
        return new_head;
    }
};