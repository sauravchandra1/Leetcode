/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        ListNode* l1 = headA, *l2 = headB, *node = 0;
        while (l1) {
            l1->val *= -1;
            l1 = l1->next;
        }
        while (l2) {
            if (l2->val < 0) {
                node = l2;
                break;
            }
            l2 = l2->next;
        }
        l1 = headA;
        while (l1) {
            l1->val *= -1;
            l1 = l1->next;
        }
        return node;
    }
};