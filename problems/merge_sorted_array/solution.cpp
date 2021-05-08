class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        int len = m + n;
        int l1 = m - 1, l2 = len - 1;
        int p = 0;
        while (l1 >= 0) nums1[l2--] = nums1[l1--];
        l1 = len - m, l2 = 0;
        while (l1 < len && l2 < n) {
            if (nums1[l1] < nums2[l2]) nums1[p++] = nums1[l1++];
            else nums1[p++] = nums2[l2++];
        }
        while (l1 < len) nums1[p++] = nums1[l1++];
        while (l2 < n) nums1[p++] = nums2[l2++];
    }
};