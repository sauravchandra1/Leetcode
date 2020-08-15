class Solution {
    public double findMedianSortedArrays(int[] nums1, int[] nums2) {
        int n1 = nums1.length;
        int n2 = nums2.length;
        int n = n1 + n2;
        int m = (n - 1) / 2;
        int mthnum = find(nums1, nums2, 0, 0, m + 1);
        int mnext = (n) / 2;
        if (m == mnext) return mthnum;
        return (mthnum + find(nums1, nums2, 0, 0, mnext + 1)) / 2.0;
    }
    int find(int[] nums1, int[] nums2, int start1, int start2, int k) {
        if (start1 >= nums1.length) return nums2[start2 + k - 1];
        if (start2 >= nums2.length) return nums1[start1 + k - 1];
        if (k == 1) { // 1 means first element
            return Math.min(nums1[start1], nums2[start2]);
        }

        int mid1 = Integer.MAX_VALUE, mid2 = Integer.MAX_VALUE;
        if (start1 + k / 2 - 1 < nums1.length) mid1 = nums1[start1 + k / 2 - 1];
        if (start2 + k / 2 - 1 < nums2.length) mid2 = nums2[start2 + k / 2 - 1];
        if (mid1 < mid2) {
            return find(nums1, nums2, start1 + k / 2, start2, k - k / 2);
        } else {
            return find(nums1, nums2, start1, start2 + k / 2, k - k / 2);
        }
    }
}