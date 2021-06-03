class Solution {
public:
    int maxArea(int h, int w, vector<int>& horizontalCuts, vector<int>& verticalCuts) {
        sort(horizontalCuts.begin(), horizontalCuts.end());
        sort(verticalCuts.begin(), verticalCuts.end());
        int lh = horizontalCuts.size();
        int lw = verticalCuts.size();
        long long int H = horizontalCuts[0], W = verticalCuts[0];
        for (int i = 1; i < lh; i++) 
            H = max((int)H, horizontalCuts[i] - horizontalCuts[i - 1]);
        H = max((int)H, h - horizontalCuts[lh - 1]);
        for (int i = 1; i < lw; i++)
            W = max((int)W, verticalCuts[i] - verticalCuts[i - 1]);
        W = max((int)W, w - verticalCuts[lw - 1]);
        const int mod = 1e9 + 7;
        long long ans = (H * W) % mod;
        return ans;
    }
};