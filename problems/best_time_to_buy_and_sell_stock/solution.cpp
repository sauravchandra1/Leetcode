class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int _min = INT_MAX, ans = 0;
        for (auto v : prices) {
            ans = max(ans, v - _min);
            _min = min(_min, v);
        }
        return ans;
    }
};