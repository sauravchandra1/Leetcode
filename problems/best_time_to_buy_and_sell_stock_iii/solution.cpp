class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int len = prices.size();
        vector<int> ans(len + 1);
        int _max = 0;
        for (int i = len - 1; i >= 0; i--) {
            if (_max > prices[i]) 
                ans[i] = _max - prices[i];
            _max = max(_max, prices[i]);
        }
        for (int i = len - 2; i >= 0; i--) 
            ans[i] = max(ans[i], ans[i + 1]);
        int _min = prices[0];
        int res = 0;
        for (int i = 1; i < len; i++) {
            if (prices[i] > _min)
                res = max(res, prices[i] - _min + ans[i + 1]);
            _min = min(_min, prices[i]);
        }
        return max(res, ans[0]);
    }
};