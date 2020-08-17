class Solution {
public:
    int numPairsDivisibleBy60(vector<int>& time) {
        const int N = 60;
        unordered_map<int, int> mp;
        for (auto &v : time) {
            v %= N;
            mp[v]++;
        }
        int ans = 0;
        for (auto v : mp) {
            if (v.first == 0) {
                ans += (v.second * (v.second - 1)) / 2;;
                continue;
            }
            int r = N - v.first;
            if (r == N / 2) {
                ans += (v.second * (v.second - 1)) / 2;
            }
            if (r > v.first && mp.count(r) > 0) {
                ans += v.second * mp[r];
            }
        }
        return ans;
    }
};