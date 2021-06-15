class Solution {
public:
    bool makesquare(vector<int>& matchsticks) {
        const long long N = 4;
        int len = matchsticks.size();
        if (len < N) return false;
        long long sum = accumulate(matchsticks.begin(), matchsticks.end(), 0LL);
        long long side = sum / N;
        sort(matchsticks.begin(), matchsticks.end(), greater<int>());
        if (sum % N || matchsticks[0] > side) return false;
        vector<int> sq(N, 0);
        auto isDone = [&](int pos) {
            for (int i = 0; i < pos; i++) if (sq[i] == sq[pos]) return true;
            return false;
        };
        function<bool(int)> dfs = [&](int pos) {
            if (pos == len) {
                if (sq[0] == side && sq[1] == side && sq[2] == side) return true;
                return false;
            }
            for (int i = 0; i < N; i++) {
                if (sq[i] + matchsticks[pos] > side || isDone(i)) continue;
                sq[i] += matchsticks[pos];
                if (dfs(pos + 1)) return true;;
                sq[i] -= matchsticks[pos];
            }
            return false;
        };
        return dfs(0);
    }
};