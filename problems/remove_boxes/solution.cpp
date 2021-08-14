class Solution {
public:
    int removeBoxes(vector<int>& boxes) {
        const int N = 101;
        const int inf = 1e9;
        int n = boxes.size();
        int dp[N][N][N];
        for (int i = 0; i < N; i++)
            for (int j = 0; j < N; j++)
                for (int k = 0; k < N; k++)
                    dp[i][j][k] = -1;
        vector<pair<int, int>> vec;
        int val, cnt;
        for (int i = 0; i < n; i++) {
            val = boxes[i], cnt = 1;
            while (i + 1 < n && boxes[i + 1] == val) {
                i++;
                cnt++;
            }
            vec.push_back({val, cnt});
        }
        function<int(int, int, int)> dfs = [&](int i, int j, int k) {  
            if (i == j) {
                k += vec[i].second;
                return (k * k);
            }
            auto& res = dp[i][j][k];
            if (res != -1) return res;
            res = dfs(i, i, k) + dfs(i + 1, j, 0);
            for (int l = i + 2; l <= j; l++) 
                if (vec[l].first == vec[i].first) 
                    res = max(res, dfs(i + 1, l - 1, 0) + dfs(l, j, k + vec[i].second));
            return res;
        };    
        return dfs(0, vec.size() - 1, 0);
    }
};