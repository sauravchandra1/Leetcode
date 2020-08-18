class Solution {
    public:
        void merge(vector < int > & nums1, int m, vector < int > & nums2, int n) {
            int size = nums1.size();
            if (nums2.size() == 0) return;
            int a = size;
            while ((a - m) != 0) {
                nums1.pop_back();
                a--;
            }
            for (int i = 0; i < n; i++) {
                nums1.push_back(nums2[i]);

            }
            sort(nums1.begin(), nums1.end());

        }
};