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
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        vector<int> vec;
        for (auto curr : lists) {
            while (curr != NULL) {
                vec.push_back(curr->val);
                curr = curr->next;
            }
        }
        sort(vec.begin(), vec.end());
        ListNode* head = NULL;
        ListNode* prev = NULL;
        for (auto v : vec) {
            ListNode* temp = new ListNode(v);
            if (head == NULL) {
                head = temp;
                prev = temp;
            } else {
                prev->next = temp;
                prev = temp;
            }
        }
        return head;
    }
};