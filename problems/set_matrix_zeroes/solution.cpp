class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        int n = matrix.size();
        int m = matrix[0].size();
        bool first_row = false, first_column = false;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (!matrix[i][j]) {
                    if (i == 0) first_row = true;
                    if (j == 0) first_column = true;
                    if (i && j) matrix[i][0] = matrix[0][j] = 0;
                }
            }
        }
        for (int i = 1; i < n; i++) 
            if (!matrix[i][0]) 
                for (int j = 1; j < m; j++)
                    matrix[i][j] = 0;
        for (int j = 1; j < m; j++)
            if (!matrix[0][j])
                for (int i = 1; i < n; i++)
                    matrix[i][j] = 0;
        if (first_row) 
            for (int j = 0; j < m; j++) 
                matrix[0][j] = 0;
        if (first_column)
            for (int i = 0; i < n; i++)
                matrix[i][0] = 0;
    }
};