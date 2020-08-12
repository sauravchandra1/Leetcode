class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        multiset<int> ml;
        int len = nums.size();
        vector<int> ans;
        for (int i = 0; i < k; i++) ml.insert(nums[i]);
        ans.push_back(*ml.rbegin());
        auto it = ml.find(nums[0]);
        ml.erase(it);
        for (int i = k; i < len; i++) {
            ml.insert(nums[i]);
            ans.push_back(*ml.rbegin());
            auto it = ml.find(nums[i - k + 1]);
            ml.erase(it);
        }
        return ans;
    }
};