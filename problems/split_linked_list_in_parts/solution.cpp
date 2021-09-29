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
    vector<ListNode*> splitListToParts(ListNode* head, int k) {
        int len = 0;
        ListNode* curr = head;
        while (curr) {
            len++;
            curr = curr->next;
        }
        int d = len / k;
        int rem = len % k;
        curr = head;
        vector<ListNode*> ans(k);
        for (int i = 0; i < k; i++) {
            if (!head) break;
            int l = d + (rem ? 1 : 0);
            if (rem) rem--;
            ans[i] = head;
            curr = head;
            while (l-- && curr) {
                if (l == 0) {
                    head = curr->next;
                    curr->next = 0;
                } else curr = curr->next;
            }
        }
        return ans;
    }
};