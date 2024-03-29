class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int len = prices.size();
        int _min = prices[0], ans = 0;
        for (int i = 1; i < len; i++) {
            ans = max(ans, prices[i] - _min);
            _min = min(_min, prices[i]);
        }
        return ans;
    }
};