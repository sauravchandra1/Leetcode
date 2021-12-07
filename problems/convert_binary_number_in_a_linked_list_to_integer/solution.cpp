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
    int p;
public:
    Solution() { p = 1; }
    int getDecimalValue(ListNode* head) {
        int res = 0;
        if (head->next == 0) res = head->val * p;  
        else res = getDecimalValue(head->next) + (head->val * p);
        p *= 2;
        return res;
    }
};