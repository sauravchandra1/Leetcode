class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        bool ok = false;
        int n = matrix.size();
        int m = (n ? matrix[0].size() : 0);
        if (!n || !m) return false;
        int i = 0, j = m - 1;
        while (i < n && j >= 0) {
            if (matrix[i][j] > target) j--;
            else if (matrix[i][j] < target) i++;
            else return true;
        }
        return false;
    }
};