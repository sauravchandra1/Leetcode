class Solution {
public:
    bool canPlaceFlowers(vector<int>& f, int n) {
        int idx = 0;
        auto before = [&](int i) {
            i--;
            if (i >= 0) return f[i] == 0;
            return true;
        };
        auto after = [&](int i) {
            i++;
            if (i < f.size()) return f[i] == 0;
            return true;
        };
        while (idx < f.size()) {
            if (before(idx) && after(idx) && !f[idx]) {
                f[idx] = 1;
                n--;
            }
            idx++;
        }
        return n <= 0;
    }
};