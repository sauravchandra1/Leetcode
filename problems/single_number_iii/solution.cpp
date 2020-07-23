class Solution {
public:
    vector<int> singleNumber(vector<int>& nums) {
        int bit = 0;
        for (auto v : nums) bit ^= v;
        bit = bit & (-bit);
        int a = 0, b = 0;
        for (auto v : nums) {
            if (v & bit) a = a ^ v;
            else b = b ^ v;
        }
        vector<int> ans{a, b};
        return ans;
    }
};