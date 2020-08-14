class Solution {
    const int INF = 1e9;
    int n;
    unordered_map<string, int> dp;
    int fun(string a, string b, int pos){
        if(pos == n - 1) return 0;
        string query = a + to_string(pos);
        if(dp.count(query)) return dp[query];
        if(a[pos] == b[pos]) {
            return fun(a, b, pos + 1);
        };
        int ans = INF;
        for(int i = pos + 1; i < n; i++){
            if(a[i] == b[pos]) {
                swap(a[pos], a[i]);
                ans = min(ans, 1 + fun(a, b, pos + 1));
                swap(a[pos], a[i]);
            }
        }
        return dp[query] = ans;
    }
public:
    int kSimilarity(string A, string B) {
        n = A.size();
        return fun(A, B, 0);
    }
};