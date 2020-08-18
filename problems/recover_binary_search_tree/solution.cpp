class Solution {
    public:
        void correct_bst(TreeNode * root, TreeNode * & first, TreeNode * & middle, TreeNode * & last, TreeNode * & prev) {
            if (root) {
                correct_bst(root -> left, first, middle, last, prev);
                if (prev && root -> val < prev -> val) {
                    if (!first) {
                        first = prev;
                        middle = root;
                    } else
                        last = root;
                }
                prev = root;
                correct_bst(root -> right, first, middle, last, prev);
            }
        }
    void recoverTree(TreeNode * root) {
        TreeNode * first, * last, * middle, * prev;
        first = middle = last = prev = NULL;
        correct_bst(root, first, middle, last, prev);
        if (first && last)
            swap(first -> val, last -> val);
        else if (first && middle)
            swap(first -> val, middle -> val);
    }
};