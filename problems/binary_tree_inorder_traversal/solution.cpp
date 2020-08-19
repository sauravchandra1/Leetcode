class Solution {
public:
    vector<int> inorderTraversal(TreeNode* root) {
        TreeNode *curr = root;
        vector<int> sol;
        stack<TreeNode*> st;
        while(curr || !st.empty()){
            while(curr){
                st.push(curr);
                curr = curr->left;
            }
            curr = st.top();
            st.pop();
            sol.push_back(curr->val);
            curr = curr->right;
        }
        return sol;
    }
};