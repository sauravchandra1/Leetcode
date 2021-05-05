class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        int len = nums2.size();
        stack<int> stk;
        unordered_map<int, int> mp;
        for (int i = 0; i < len; i++) {
            while (!stk.empty() && stk.top() < nums2[i]) {
                int val = stk.top();
                stk.pop();
                mp[val] = nums2[i];
            }
            stk.push(nums2[i]);
        }
        for (int i = 0; i < nums1.size(); i++) {
            if (mp.count(nums1[i]) > 0) nums1[i] = mp[nums1[i]];
            else nums1[i] = -1;
        }
        return nums1;
    }
};