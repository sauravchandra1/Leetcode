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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode* head = 0, *curr = 0;
        head = new ListNode(0);
        curr = head;
        int sum = 0, carry = 0;
        while (l1 || l2) {
            sum = 0;
            if (l1) sum += l1->val;
            if (l2) sum += l2->val;
            sum += carry;
            carry = 0;
            if (sum >= 10) {
                sum -= 10;
                carry++;
            }
            if (l1) l1 = l1->next;
            if (l2) l2 = l2->next;
            curr->next = new ListNode(sum);
            curr = curr->next;
        }
        if (carry) {
            curr->next = new ListNode(carry);
        }
        return head->next;
    }
};