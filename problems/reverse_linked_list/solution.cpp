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
    ListNode* reverseList(ListNode* head) {
        ListNode* curr = head, *next = 0;
        if (curr) next = curr->next;
        if (curr) curr->next = 0;
        while (next) {
            ListNode* temp = next->next;
            next->next = curr;
            curr = next;
            next = temp;
        }
        head = curr;
        return head;
    }
};