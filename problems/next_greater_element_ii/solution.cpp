class Solution {
public:
    vector<int> nextGreaterElements(vector<int>& nums) {
        int len = nums.size();
        len += len;
        vector<int> vec;
        int n = nums.size();
        for (int i = 0; i < len; i++) {
            vec.push_back(nums[i % n]);
        }
        vector<int> ans(n, -1);
        stack<int> stk;
        for (int i = len - 2; i >= n; i--) {
            while (!stk.empty() && vec[i] >= stk.top()) {
                stk.pop();
            } 
            stk.push(vec[i]);
        }
        for (int i = n - 1; i >= 0; i--) {
            while (!stk.empty() && stk.top() <= vec[i]) stk.pop();
            if (!stk.empty() && stk.top() > vec[i]) ans[i] = stk.top();
            stk.push(vec[i]);
        }
        return ans;
    }
};