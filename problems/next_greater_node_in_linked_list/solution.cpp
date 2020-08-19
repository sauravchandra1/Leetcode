class Solution {
    public:
    stack < int > st;
    vector < int > ans;
    void check(ListNode * head) {
        if (!head) return;
        check(head -> next);
        if (st.empty()) {
            st.push(head -> val);
            ans.push_back(0);
        } else {
            while (!st.empty() && head -> val >= st.top()) {
                st.pop();
            }
            if (st.empty()) {
                ans.push_back(0);
                st.push(head -> val);
            } else {
                ans.push_back(st.top());
                st.push(head -> val);
            }
        }
    }
    vector < int > nextLargerNodes(ListNode * head) {
        check(head);
        if (!head) return ans;
        reverse(ans.begin(), ans.end());
        return ans;
    }
};