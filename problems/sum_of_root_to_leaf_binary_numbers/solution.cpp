class Solution {
    public:
        vector < int > vec;
    int sum = 0;
    int sumRootToLeaf(TreeNode * root) {
        calculate(root);
        return sum;
    }

    void calculate(TreeNode * root) {
        if (root == NULL)
            return;
        vec.push_back(root -> val);
        sumRootToLeaf(root -> left);
        if (root -> left == NULL && root -> right == NULL) {
            int p = vec.size() - 1;
            for (int i = vec.size() - 1; i >= 0; i--) {
                sum = sum + (vec[i] * pow(2, p - i));
            }
        }
        sumRootToLeaf(root -> right);
        vec.pop_back();
    }
};