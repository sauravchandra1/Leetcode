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
    ListNode* oddEvenList(ListNode* head) {
        if (head == 0) return head;
        ListNode* curr = head, *first_even = head->next, *last_odd = 0, *t = 0;
        int idx = 1;
        //last odd --> first even
        while (curr) {
            t = curr->next;
            if (t) curr->next = curr->next->next;
            if (idx & 1) last_odd = curr;
            idx++;
            curr = t;
        }
        last_odd->next = first_even;
        return head;
    }
};