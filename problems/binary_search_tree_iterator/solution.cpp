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
class BSTIterator {
public:
    stack<TreeNode*> stk;
    TreeNode* curr = NULL;
    TreeNode* r = NULL;
    BSTIterator(TreeNode* root) {
        stk.push(root);
        r = root;
        curr = root;
    }
    
    int next() {
        TreeNode* tmp = NULL;
        while (!stk.empty() || curr != NULL) {
            if (curr == NULL) {
                tmp = stk.top();
                stk.pop();
                curr = tmp->right;
                return tmp->val;
            } 
            while (curr != NULL) {
                if (curr != r) 
                    stk.push(curr);
                curr = curr->left;
            }
        }
        return 0;
    }
    
    bool hasNext() {
        if (curr != NULL || !stk.empty()) return true;
        return false;
    }
};

/**
 * Your BSTIterator object will be instantiated and called as such:
 * BSTIterator* obj = new BSTIterator(root);
 * int param_1 = obj->next();
 * bool param_2 = obj->hasNext();
 */