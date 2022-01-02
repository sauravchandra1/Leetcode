class Solution {
public:
    int numPairsDivisibleBy60(vector<int>& time) {
        const int N = 60;
        vector<int> vec(N);
        for (auto& v : time) vec[v % N]++;
        long long ans = (vec[0] * (vec[0] - 1)) / 2;
        ans += (vec[30] * (vec[30] - 1)) / 2;
        for (int i = 1; i < N / 2; i++) ans += vec[i] * vec[N - i];
        return ans;
    }
};