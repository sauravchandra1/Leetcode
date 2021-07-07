class Solution {
public:
    int kthSmallest(vector<vector<int>>& matrix, int k) {
        int n = matrix.size();
        auto get = [&](int val) {
            int r = 0, c = n - 1, ans = 0;
            while (r < n && c >= 0) {
                if (matrix[r][c] <= val) {
                    ans += c + 1;
                    r++;
                } else c--;
            }
            return ans;
        };
        int l = matrix[0][0], r = matrix[n - 1][n - 1], mid;
        while (l < r) {
            mid = (l + r) / 2;
            if (get(mid) < k) l = mid + 1;
            else r = mid;
        }
        return l;
    }
};