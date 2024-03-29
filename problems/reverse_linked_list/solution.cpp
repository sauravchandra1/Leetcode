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
        if (!head) return head;
        ListNode *curr = head, *next = head->next, *temp = 0;
        curr->next = 0;
        while (next) {
            temp = next->next;
            next->next = curr;
            curr = next;
            next = temp;
        }
        return curr;
    }
};