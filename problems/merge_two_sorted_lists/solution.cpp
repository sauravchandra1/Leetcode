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
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        ListNode* n = new ListNode();
        ListNode* root = n;
        function<void(int)> add = [&](int val) {
            ListNode* t = new ListNode(val);
            n->next = t;
            n = t;
        };
        while (l1 != NULL && l2 != NULL) {
            if (l1->val < l2->val) {
                add(l1->val);
                l1 = l1->next;
            } else {
                add(l2->val);
                l2 = l2->next;
            }
        }
        while (l1 != NULL) {
            add(l1->val);
            l1 = l1->next;
        }
        while (l2 != NULL) {
            add(l2->val);
            l2 = l2->next;
        }
        return root->next;
    }
};