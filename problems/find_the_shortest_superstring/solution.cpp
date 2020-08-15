int dp[12][(1 << 12)], cost[12][12];

int match(string & s1, string & s2) {
    for (int i = 0; i < s1.size(); i++) {
        int j = i, k = 0;
        while (j < s1.size() && k < s2.size()) {
            if (s1[j] != s2[k]) break;
            j++;
            k++;
        }
        if (j >= s1.size()) return s1.size() - i;
    }
    return 0;
}

void pre(vector < string > & v) {
    for (int i = 0; i < v.size(); i++) {
        for (int j = 0; j < v.size(); j++) {
            if (i == j) continue;
            cost[i][j] = match(v[i], v[j]);
        }
    }
}

int n = 0;
map < pair < int, int > , int > trace;
vector < int > len;

int solve(int idx, int mask) {
    if (mask == (1 << n) - 1) return 0;
    if (dp[idx][mask] != -1) return dp[idx][mask];
    dp[idx][mask] = 1e9;

    for (int i = 0; i < n; i++) {
        if ((mask & (1 << i)) == 0) {
            int temp = len[i] - cost[idx][i] + solve(i, mask | (1 << i));
            if (temp < dp[idx][mask]) {
                dp[idx][mask] = temp;
                trace[{
                    idx,
                    mask
                }] = i;
            }
        }
    }
    return dp[idx][mask];
}

class Solution {
    public:
        string shortestSuperstring(vector < string > & A) {
            trace.clear();
            len.clear();
            for (auto a: A) len.push_back(a.size());
            n = A.size();
            pre(A);
            memset(dp, -1, sizeof dp);
            int min_ = 1e9, best = 0;
            for (int i = 0; i < A.size(); i++) {
                int temp = A[i].size() + solve(i, (1 << i));
                if (temp < min_) {
                    min_ = temp;
                    best = i;
                }
            }
            string ans = A[best];
            int mask = (1 << best);
            for (int i = 1; i < n; i++) {
                int prev = best;
                best = trace[{
                    best,
                    mask
                }];
                ans += A[best].substr(cost[prev][best], A[best].size() - cost[prev][best]);
                mask |= (1 << best);
            }
            return ans;
        }
};