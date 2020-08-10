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
        auto get = [&](int a, int b, int c) {
            pair<int, int> pp;
            pp.first = (a + b + c) % 10;
            pp.second = (a + b + c) / 10;
            return pp;
        };
        auto get_len = [&](ListNode* head) {
            int len = 0;
            ListNode* last = NULL;
            while (head != NULL) {
                last = head;
                head = head->next;
                len++;
            }
            last->next = new ListNode(0);
            return len;
        };
        auto add = [&](ListNode* head, int cnt) {
            while (head->next != NULL) head = head->next;
            while (cnt--) {
                head->next = new ListNode(0);
                head = head->next;
            }
        };
        ListNode* root = NULL;
        auto remove_zero = [&](ListNode* head) {
            ListNode* last = NULL;
            while (head != NULL) {
                if (head->val != 0) last = head;
                head = head->next;
            }
            if (last != NULL) last->next = NULL;
            else root->next = NULL;
        };
        int len1 = get_len(l1), len2 = get_len(l2);
        if (len1 > len2) add(l2, len1 - len2);
        else add(l1, len2 - len1);
        ListNode* curr = l1;
        pair<int, int> pp;
        ListNode* tt = NULL;
        int cc = 0;
        while (l1 != NULL) {
            pp = get(l1->val, l2->val, cc);
            tt = new ListNode(0);
            tt->val = pp.first;
            cc = pp.second;
            if (curr == l1) root = tt;
            else curr->next = tt;
            curr = tt;
            l1 = l1->next;
            l2 = l2->next;
        }
        remove_zero(root);
        return root;
    }
};