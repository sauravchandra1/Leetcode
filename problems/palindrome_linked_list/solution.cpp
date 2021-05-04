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
    bool isPalindrome(ListNode* head) {
        string str;
        while (head) {
            str += head->val + '0';
            head = head->next;
        }
        int l = 0, r = str.size() - 1;
        while (l < r) {
            if (str[l] != str[r]) return false;
            l++, r--;
        }
        return true;
    }
};