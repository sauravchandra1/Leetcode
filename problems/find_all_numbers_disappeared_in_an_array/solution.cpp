class Solution {
public:
    vector<int> findDisappearedNumbers(vector<int>& nums) {
        int len = nums.size();
        vector<int> ans;
        const int N = 1e6;
        const int M = 1e5;
        for (auto& v : nums) {
            int t = v % M; 
            nums[t - 1] += N;
        }
        for (int i = 0; i < len; i++) 
            if (nums[i] < N) ans.push_back(i + 1);
        return ans;
    }
};