class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        heights.push_back(0);
        int len = heights.size();
        stack<int> stk;
        int ans = 0, top;
        for (int i = 0; i < len; i++) {
            while (!stk.empty() && heights[stk.top()] >= heights[i]) {
                top = stk.top();
                stk.pop();
                if (stk.empty()) ans = max(ans, heights[top] * i);
                else ans = max(ans, heights[top] * (i - stk.top() - 1));
            }
            stk.push(i);
        }
        return ans;
    }
};