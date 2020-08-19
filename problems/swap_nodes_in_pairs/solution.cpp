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
    ListNode* swapPairs(ListNode* head) {
        ListNode* prev = NULL;
        ListNode* curr = NULL;
        ListNode* nxt = NULL;
        if (head == NULL) return head;
        prev = NULL;
        curr = head;
        nxt = curr->next;
        while (nxt) {
            if (curr == head) {
                head = curr->next;
            }
            curr->next = nxt->next;
            nxt->next = curr;
            if (prev) {
                prev->next = nxt;
            }
            prev = curr;
            curr = curr->next;
            if (!curr) break;
            nxt = curr->next;
        }
        return head;
    }
};