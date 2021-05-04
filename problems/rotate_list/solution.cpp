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
    ListNode* rotateRight(ListNode* head, int k) {
        int len = 0;
        ListNode* curr = head;
        while (curr) {
            curr = curr->next;
            len++;
        }
        if (head == 0) return head;
        k = k % len;
        if (k == 0 || len == 1) return head;
        ListNode* slow = head, *fast = head;
        while (k--) fast = fast->next;
        ListNode* prev = 0;
        while (fast) {
            fast = fast->next;
            prev = slow;
            slow = slow->next;
        }
        ListNode* newHead = slow;
        while (slow && slow->next) slow = slow->next;
        if (slow) slow->next = head;
        if (prev) prev->next = 0;
        return newHead;
    }
};