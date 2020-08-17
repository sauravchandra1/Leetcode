class Solution {
    public:
        ListNode * addTwoNumbers(ListNode * l1, ListNode * l2) {

            string s1, s2;
            while (l1 != NULL) {
                s1.push_back(l1 -> val + '0');
                l1 = l1 -> next;
            }
            while (l2 != NULL) {
                s2.push_back(l2 -> val + '0');
                l2 = l2 -> next;
            }

            string f;
            int i = s1.length() - 1, j = s2.length() - 1;
            int carry = 0;
            while (i >= 0 or j >= 0) {
                int a = (i >= 0) ? s1[i] - '0' : 0;
                int b = (j >= 0) ? s2[j] - '0' : 0;
                int temp = (a + b + carry);

                f.push_back(temp % 10 + '0');
                carry = temp / 10;
                i--;
                j--;

            }

            if (carry != 0)
                f.push_back(carry + '0');


            ListNode * curr = NULL, * head = NULL, * prev = NULL;
            for (auto x: f) 
            {
                ListNode * N = new ListNode(x - '0');
                N -> next = prev;
                prev = N;
                head = prev;
            }

            return head;

        }
};