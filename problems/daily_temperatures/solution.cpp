class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& T) {
        stack<int> stk;
        int n = T.size();
        vector<int> ans(n, 0);
        for (int i = n - 1; i >= 0; i--) {
            while (!stk.empty() && T[stk.top()] <= T[i]) stk.pop();
            if (!stk.empty()) {
                ans[i] = stk.top() - i;
            }
            stk.push(i);
        }
        return ans;
    }
};