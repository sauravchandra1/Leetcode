class Solution {
public:
    int numOfSubarrays(vector<int>& arr) {
        int n = arr.size();
        int cnt = 0;
        vector<int> vec(n, 0);
        for (int i = n - 1; i >= 0; i--) {
            if (arr[i] & 1) {
                vec[i] = cnt + 1;
                cnt = 0;
            } else cnt++;
        }
        vector<int> ans(n);
        int l = 0, sl = 0;
        for (int i = n - 1; i >= 0; i--) {
            if (arr[i] & 1) {
                ans[i] = vec[i] + sl;
                sl = l;
                l = ans[i];
            } else {
                if (i + 1 < n) ans[i] = ans[i + 1];
            }
        }
        long long res = 0;
        int mod = 1e9 + 7;
        for (int i = 0; i < n; i++) res = (res % mod + ans[i] % mod) % mod;
        return res;
        
    }
};