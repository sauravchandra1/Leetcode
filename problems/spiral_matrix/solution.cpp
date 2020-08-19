class Solution {
    public:
        vector < int > spiralOrder(vector < vector < int >> & matrix) {
            vector < int > ans;
            int m = matrix.size(); 
            if (m == 0) return ans;
            if (m == 1) return matrix[0];
            int n = matrix[0].size(); 
            int top_row = 0;
            int bottom_row = m - 1;
            int left_col = 0;
            int right_col = n - 1;
            int index = 0;
            while ((top_row <= bottom_row) && (left_col <= right_col)) {
                for (int i = left_col; i <= right_col; i++) {
                    ans.push_back(matrix[top_row][i]);
                }
                top_row++;
                if (top_row > bottom_row) break;
                for (int j = top_row; j <= bottom_row; j++) {
                    ans.push_back(matrix[j][right_col]);
                }
                right_col--;
                if (right_col < left_col) break;
                for (int k = right_col; k >= left_col; k--) {
                    ans.push_back(matrix[bottom_row][k]);
                }
                bottom_row--;
                if (bottom_row < top_row) break;
                for (int l = bottom_row; l >= top_row; l--) {
                    ans.push_back(matrix[l][left_col]);
                }
                left_col++;
                if (left_col > right_col) break;
            }

            return ans;
        }
};