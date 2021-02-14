class Solution {
public:
    int _i, _j;
    int kthElement(vector<int>& arr1, vector<int>& arr2, int n, int m, int k)
    {
        // cout << "n->" << n << "m->" << m << "k->" << k << endl;
        if (k > n + m || k < 1) return -1;
        if (n < m) {
            swap(_i, _j);
            return kthElement(arr2, arr1, m, n, k);
        }
        if (m == 0) return arr1[_i + k - 1];
        if (k == 1) return min(arr1[_i + 0], arr2[_j + 0]);
        int i = min(n, k / 2);
        int j = min(m, k / 2);
        // cout << "i->" << i << " " << "j->" << j << endl;
        if (arr1[_i + i - 1] < arr2[_j + j - 1]) {
            _i += i;
            return kthElement(arr1, arr2, n - i, m, k - i);
        } else {
            _j += j;
            return kthElement(arr1, arr2, n, m - j, k - j);
        }
    }
    
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int n = nums1.size();
        int m = nums2.size();
        int k = (n + m) / 2;
        _i = _j = 0;
        if ((n + m) & 1) return kthElement(nums1, nums2, n, m, k + 1);
        else {
            double a = kthElement(nums1, nums2, n, m, k);
            _i = _j = 0;
            double b = kthElement(nums1, nums2, n, m, k + 1);
            // cout << a << " " << b << " " << k << endl;
            return (a + b) / 2.0;
        }
    }
};