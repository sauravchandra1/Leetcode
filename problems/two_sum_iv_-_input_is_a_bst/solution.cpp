class Solution {
    public:

        bool ans = 0;
    void traverse(struct TreeNode * root, int k, vector < int > & v) {
        if (root == NULL)
            return;

        else {
            traverse(root -> left, k, v);
            if (binary_search(v.begin(), v.end(), (k - (root -> val))))
                ans = 1;
            v.push_back(root -> val);
            traverse(root -> right, k, v);
        }
    }

    bool findTarget(TreeNode * root, int k) {

        vector < int > v;
        traverse(root, k, v);
        return ans;
    }
};