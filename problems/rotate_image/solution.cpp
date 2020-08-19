class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        int row = matrix.size();
        int col = matrix[0].size();
        int start = 0, end = row - 1;
        while (start < end) {
            swap(matrix[start], matrix[end]);
            start++;
            end--;
        }
        for (int i = 0; i < row; i++) {
            for (int j = i + 1; j < col; j++) {
                swap(matrix[i][j], matrix[j][i]);
            }
        }
    }
};