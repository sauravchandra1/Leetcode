/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    void insertAfter(ListNode* curr, ListNode* node) {
        ListNode* next = curr->next;
        curr->next = node;
        node->next = next;
    }
    void reorderList(ListNode* head) {
        stack<ListNode*> stk;
        ListNode* curr = head, *node = 0;
        while (curr != 0) {
            stk.push(curr);
            curr = curr->next;
        }
        int len = stk.size();
        if (len <= 2) return;
        int n = (len & 1 ? len / 2 : (len - 1) / 2);
        curr = head;
        while (n--) {
            node = stk.top();
            stk.pop();
            insertAfter(curr, node);
            curr = node->next;
        }
        if (len & 1) curr->next = 0;
        else curr->next->next = 0;
        return;
    }
};