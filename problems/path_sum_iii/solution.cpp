class Solution {
int ans = 0;
public:
        void count(TreeNode * root, int sum) {
            if (root -> left == root -> right) {
                if (root -> val == sum)
                    ans++;
                return;
            }
            if (root -> val == sum)
                ans++;

            if (root -> left) {
                count(root -> left, sum - root -> val);
            }
            if (root -> right) {
                count(root -> right, sum - root -> val);
            }
        }

    int pathSum(TreeNode * root, int sum) {
        if (root == NULL)
            return ans;
        count(root, sum);
        if (root -> left)
            pathSum(root -> left, sum);
        if (root -> right)
            pathSum(root -> right, sum);
        return ans;
    }
};