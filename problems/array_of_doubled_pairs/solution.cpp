class Solution {
public:
    bool canReorderDoubled(vector<int>& arr) {
        int n = arr.size();
        sort(arr.begin(), arr.end(), [&](const int& a, const int& b) {
            if (a < 0 && b < 0) return (a > b);
            return (a < b);
        });
        unordered_map<int, int> cnt;
        for (auto& v : arr) cnt[v]++;
        for (auto& v : arr) {
            if (cnt[v]) {
                if (!cnt[2 * v]) return false;
                cnt[v]--;
                cnt[2 * v]--;
            }
        }
        return true;
    }
};