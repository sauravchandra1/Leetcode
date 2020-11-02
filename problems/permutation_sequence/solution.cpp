class Solution {
public:
    string getPermutation(int n, int k) {
        vector<int> fact(n + 1);
        fact[0] = 1;
        for (int i = 1; i <= n; i++) fact[i] = i * fact[i - 1];
        vector<int> vec(n);
        iota(vec.begin(), vec.end(), 1);
        string ans = "";
        int idx;
        for (int i = n; i >= 1; i--) {
            idx = k / fact[i - 1] + (k % fact[i - 1] ? 1 : 0);
            ans += vec[idx - 1] + '0';
            vec.erase(vec.begin() + idx - 1);
            k -= (fact[i - 1] * (idx - 1));
        }
        return ans;
    }
};