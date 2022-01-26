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
    void pushToStack(stack<TreeNode*>& stk, TreeNode* root) {
        if (root != NULL) {
            stk.push(root);
            while (root->left) {
                stk.push(root->left);
                root = root->left;
            }
        }
    }
    void pushToVector(vector<int>& ans, stack<TreeNode*>& stk) {
        ans.push_back(stk.top()->val);
        TreeNode* right = stk.top()->right;
        stk.pop();
        pushToStack(stk, right);
    }
    vector<int> getAllElements(TreeNode* root1, TreeNode* root2) {
        stack<TreeNode*> stk1, stk2;
        vector<int> ans;
        pushToStack(stk1, root1);
        pushToStack(stk2, root2);
        while (!stk1.empty() || !stk2.empty()) {
            if (!stk1.empty() && !stk2.empty()) {
                if (stk1.top()->val <= stk2.top()->val) {
                    pushToVector(ans, stk1);
                }
                else {
                    pushToVector(ans, stk2);
                }
            } else if (!stk1.empty()) 
                pushToVector(ans, stk1);
            else 
                pushToVector(ans, stk2);
        }
        return ans;
    }
};