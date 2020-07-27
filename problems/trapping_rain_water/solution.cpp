class Solution {
public:
    int trap(vector<int>& height) {
        int n = height.size(), ans = 0;
        stack<int> stk;
        for (int i = 0; i < n; i++) {
            if (stk.empty()) stk.push(i);
            else if (height[i] < height[stk.top()]) stk.push(i);
            else {
                int min_i = stk.top();
                stk.pop();
                while (true) {
                    if (stk.empty()) break;
                    else {
                        int tp = stk.top();
                        ans += (min(height[i], height[tp]) - height[min_i]) * 
                            (i - tp - 1);
                    }
                    
                    if (height[stk.top()] <= height[i]) {
                        min_i = stk.top();
                        stk.pop();
                    }
                    else break;
                }
                stk.push(i);
            }
        }
        return ans;
    }
};