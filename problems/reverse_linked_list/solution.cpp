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
        if (head == NULL) return head;
        ListNode* root = new ListNode();
        root->val = head->val;
        head = head->next;
        ListNode* curr = root;
        ListNode* tt = NULL;
        while (head != NULL) {
            tt = new ListNode(head->val);
            tt->next = curr;
            curr = tt;
            head = head->next;
        }
        return curr;
    }
};