class Solution {
public:
    int minNumberOperations(vector<int>& target) {
        int ans = 0;
        int n = target.size();
        int _max = 0;
        int last = 0;
        const int N = 1e5 + 10;
        int _min = N, lm = 0;
        for (int i = 0; i < n; i++) {
            _max = target[i];
            last = target[i];
            _min = N;
            while (i < n && target[i] <= last) {
                last = target[i];
                _min = min(_min, target[i]);
                _max = max(_max, target[i]);
                i++;
            }
            i--;
            ans += max(0, (_max - lm));
            lm = _min;
            // cout << ans << " " << i << " " << lm << endl;
        }
        return ans;
    }
};