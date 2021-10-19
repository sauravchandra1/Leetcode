class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        stack<int> stk;
        int len = nums2.size();
        stk.push(nums2[len - 1]);
        unordered_map<int, int> ans;
        for (int i = len - 2; i >= 0; i--) {
            while (!stk.empty() && nums2[i] > stk.top()) stk.pop();
            if (!stk.empty()) ans[nums2[i]] = stk.top();
            stk.push(nums2[i]);
        }
        for (int i = 0; i < nums1.size(); i++) {
            if (ans.count(nums1[i]) > 0) nums1[i] = ans[nums1[i]];
            else nums1[i] = -1;
        }
        return nums1;
    }
};