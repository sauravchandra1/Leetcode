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
    ListNode* insertionSortList(ListNode* head) {
        ListNode* curr = head;
        while (curr->next) {
            ListNode* next = curr->next;
            while (next) {
                if (next->val < curr->val) swap(next->val, curr->val);
                next = next->next;
            }
            curr = curr->next;
        }
        return head;
    }
};