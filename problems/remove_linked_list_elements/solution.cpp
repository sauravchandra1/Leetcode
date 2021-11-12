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
    ListNode* removeElements(ListNode* head, int val) {
        ListNode *prev = head, *curr = 0;
        while (prev && prev->val == val) prev = prev->next;
        head = prev;
        if (prev) curr = prev->next;
        while (curr) {
            while (curr && curr->val == val) curr = curr->next;
            prev->next = curr;
            prev = curr;
            if (prev) curr = prev->next;
        }
        return head;
    }
};