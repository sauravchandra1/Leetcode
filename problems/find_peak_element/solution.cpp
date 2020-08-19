class Solution {
public:
    int findPeakElement(vector<int>& nums) {
        int l = 0, r = nums.size() - 1, mid, res = 0;
        while( l < r) {
            mid = l + ( r - l)/2;
            if( nums[mid] < nums[mid + 1])
                res = l = mid + 1;
            else 
                res = r = mid;
        }
        return res;
    }
};