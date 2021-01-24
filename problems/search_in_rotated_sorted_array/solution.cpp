class Solution {
public:
    int search(vector<int>& nums, int target) {
        int i = 0;
        for (auto v : nums) {
            if (v == target) return i;
            i++;
        }
        return -1;
    }
};