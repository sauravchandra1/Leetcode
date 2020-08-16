class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int n = matrix.size();
        if (n == 0) return false;
        int m = matrix[0].size();
        if (m == 0) return false;
        if (n == 1 && m == 1 && target == matrix[0][0]) return true;
        int l = 0, r = n - 1, mid;
        while (l < r) {
            mid = (l + r) / 2;
            if (target < matrix[mid][m - 1]) {
                r = mid;
            } else if (target > matrix[mid][m - 1]) {
                l = mid + 1;
            } else return true;
        }
        int _r = r;
        l = 0, r = m - 1;
        while (l < r) {
            mid = (l + r) / 2;
            if (target < matrix[_r][mid]) {
                r = mid - 1;
            } else if (target > matrix[_r][mid]) {
                l = mid + 1;
            } else return true;
        }
        if (matrix[_r][l] == target) return true;
        return false;
    }
};