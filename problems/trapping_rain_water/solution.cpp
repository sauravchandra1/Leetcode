class Solution {
public:
    int trap(vector<int>& height) {
        int len = height.size();
        vector<int> forward(len, 0), backward(len, 0);
        int idx;
        if (len == 0) return len;
        forward[0] = height[0];
        for (int i = 1; i < len; i++) 
            forward[i] = max(forward[i - 1], height[i]);
        backward[len - 1] = height[len - 1];
        for (int i = len - 2; i >= 0; i--) 
            backward[i] = max(backward[i + 1], height[i]);
        int ans = 0;
        for (int i = 0; i < len; i++) {
            ans += min(forward[i], backward[i]) - height[i];
        }
        return ans;
    }
};