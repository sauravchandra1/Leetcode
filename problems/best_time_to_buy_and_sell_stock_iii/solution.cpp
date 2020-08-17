class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int len = prices.size();
        int k = 2;
        if (len == 0) return 0;
        const int N = 2;
        if (k >= len * 2) {
            int ans = 0;
              for(int i = 1 ; i < len; i++){
                  if(prices[i] > prices[i - 1]){
                      ans += prices[i] - prices[i - 1];
                  }
              }
              return ans;
        }
        int dp[len + 1][k + 1][N];
        for (int i = 0; i <= len; i++) {
            for (int j = 0; j <= k; j++) {
                dp[i][j][0] = dp[i][j][1] = -1;
            }
        }
        function<int(int, int, int)> dfs = [&](int idx, int k, int state) {
            if (k < 0) return 0;
            if (idx == len) return 0;
            auto &res = dp[idx][k][state];
            if (res != -1) return res;
            res = 0;
            int a = 0, b = 0;
            if (state == 0) {
                a = dfs(idx + 1, k - 1, 1) - prices[idx];
                b = dfs(idx + 1, k, 0);
            } else {
                a = dfs(idx + 1, k, 0) + prices[idx];
                b = dfs(idx + 1, k, 1);
            }
            res = max(a, b);
            return res;
        };
        return dfs(0, k, 0);
    }
};