class Solution {
public:
    Node* flatten(Node* head) {
        
        if (head == NULL)
            return head;
        
        Node* dummyhead;
        Node* cur = NULL;
        
        return childseeker(head, cur, dummyhead);
    }
    
    Node* childseeker (Node* thislev, Node* cur, Node* dummyhead) {
                
        while (thislev != NULL) {
            if (cur == NULL) {
                Node* p = new Node(thislev -> val);
                dummyhead = p;
                cur = p;
            }
            else {
                Node* p = new Node(thislev -> val);
                cur -> next = p;
                p -> prev = cur;
                cur = p;
            }
            if (thislev -> child != NULL) {
                Node* temp;
                temp = thislev -> next;
                thislev = thislev -> child;
                childseeker(thislev, cur, dummyhead);
                while (cur -> next != NULL)
                    cur = cur -> next;
                thislev = temp;
            }
            else
                thislev = thislev -> next;
                        
        }
        
        return dummyhead;
    } 
    
};