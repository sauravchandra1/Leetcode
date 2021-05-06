class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        deque<pair<int, int>> dq;
        int len = nums.size();
        auto get = [&](int i) {
            while (!dq.empty() && 
                   dq.front().second < (i - k + 1)) dq.pop_front();
            if (dq.empty()) dq.push_back({nums[i], i});
            else {
                while (!dq.empty() && 
                       dq.back().first <= nums[i]) dq.pop_back();
                dq.push_back({nums[i], i});
            }
        };
        for (int i = 0; i < k - 1; i++) get(i);
        vector<int> ans;
        for (int i = k - 1; i < len; i++) {
            get(i);
            ans.push_back(dq.front().first);
        }
        return ans;
    }
};