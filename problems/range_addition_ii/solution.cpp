class Solution {
public:
    int maxCount(int m, int n, vector<vector<int>>& ops) {
        int x = m, y = n;
        for (auto v : ops) {
            x = min(x, v[0]);
            y = min(y, v[1]);
        }
        return x * y;
    }
};