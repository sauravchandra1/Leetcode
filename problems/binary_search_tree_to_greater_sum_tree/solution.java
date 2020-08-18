class Solution {
    public TreeNode bstToGst(TreeNode root) {
        helper(root, new pair(Integer.MIN_VALUE));
        return root;
    }
    
    class pair{
        int val;
        public pair(int x){
            val = x;
        }
    }
    public void helper(TreeNode root, pair p){
        if(root == null) return;
        helper(root.right, p);
        if(p.val == Integer.MIN_VALUE) p.val = root.val;
        else p.val += root.val;
        root.val = p.val;
        helper(root.left, p);
    }
}