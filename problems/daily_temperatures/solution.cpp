class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temp) {
        stack<int> stk;
        int len = temp.size();
        vector<int> ans(len, 0);
        stk.push(len - 1);
        for (int i = len - 2; i >= 0; i--) {
            while (!stk.empty() && temp[stk.top()] <= temp[i]) stk.pop();
            if (!stk.empty()) ans[i] = stk.top() - i;
            stk.push(i);
        }
        return ans;
    }
};