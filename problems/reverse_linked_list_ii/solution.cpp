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
    ListNode* reverseBetween(ListNode* head, int left, int right) {
        queue<ListNode*> Q;
        ListNode* curr = head;
        bool seen_left = false, seen_right = false;
        function<ListNode*(ListNode*, int)> dfs = [&](ListNode* curr, int pos) {
            if (pos == left) seen_left = true;
            if (seen_left) Q.push(curr);
            if (pos == right) {
                seen_right = true;
                ListNode* p = Q.front();
                Q.pop();
                p->next = curr->next;
                return p;
            }
            ListNode* next = dfs(curr->next, pos + 1);
            if (seen_right && !Q.empty()) {
                ListNode* p = Q.front();
                Q.pop();
                p->next = next;
                return p;
            } else {
                curr->next = next;
                return curr;
            }
        };
        return dfs(curr, 1);
    }
};