class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        k = nums.size() - k;
        auto partition = [&](int l, int r) {
            if (l == r) return l;
            int i = l - 1;
            for (int j = l; j < r; j++) 
                if (nums[j] < nums[r]) 
                    swap(nums[++i], nums[j]);
            swap(nums[i + 1], nums[r]);
            return i + 1;
        };
        bool ok = false;
        function<void(int, int)> quickSort = [&](int l, int r) {
            if (ok || l >= r) return;
            int p = partition(l, r);
            if (p == k) {
                ok = true;
                return;
            } else if (p > k) 
                quickSort(l, p - 1);
            else quickSort(p + 1, r);
        };
        quickSort(0, nums.size() - 1);
        return nums[k];
    }
};