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
    ListNode* reverseKGroup(ListNode* head, int k) {
        int len = 0;
        ListNode* curr = head;
        while (curr) {
            curr = curr->next;
            len++;
        }
        len = len - len % k;
        len /= k;
        ListNode* next = 0, *temp = 0, *newHead = 0, *tail = 0;
        newHead = head;
        bool ok = false;
        while (len--) { 
            curr = newHead;
            next = curr->next;
            for (int i = 1; i < k; i++) {
                temp = next->next;
                next->next = curr;
                curr = next;
                next = temp;
            }
            if (tail) tail->next = curr;
            tail = newHead;
            newHead = next;
            if (!ok) {
                head = curr;
                ok = true;
            }
        }
        if (tail) tail->next = next;
        return head;
    }
};