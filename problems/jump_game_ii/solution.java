class Solution {
    public int jump(int[] nums) {
        int len = nums.length;
        int pos = 0, des = 0, ans = 0;
        for (int i = 0; i < len - 1; i++) {
            des = Math.max(des, nums[i] + i);
            if (pos == i) {
                ans++;
                pos = des;
            }
        }
        return ans;
    }
}