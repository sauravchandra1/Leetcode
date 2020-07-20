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
        while ((head != nullptr) && (head->val == val)) head = head->next;
        ListNode* curr = head;
        ListNode* prev = head;
        if (curr != nullptr) curr = curr->next;
        while (curr != nullptr) {
            while ((curr != nullptr) && (curr->val == val)) curr = curr->next;
            prev->next = curr;
            prev = curr;
            if (curr != nullptr) curr = curr->next;
        }
        return head;
    }
};