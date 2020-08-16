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
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    TreeNode* sortedListToBST(ListNode* head) {
        vector<int> vec;
        while (head != NULL) {
            vec.push_back(head->val);
            head = head->next;
        }
        function<TreeNode*(int, int)> dfs = [&](int l, int r) {
            TreeNode* root = NULL;
            if (l > r) return root;
            int m = (l + r) / 2;
            root = new TreeNode(vec[m]);
            root->left = dfs(l, m - 1);
            root->right = dfs(m + 1, r);
            return root;
        };
        return dfs(0, vec.size() - 1);
    }
};