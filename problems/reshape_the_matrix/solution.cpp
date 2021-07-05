class Solution {
public:
    vector<vector<int>> matrixReshape(vector<vector<int>>& mat, int r, int c) {
        int n = mat.size();
        int m = mat[0].size();
        if (n * m != r * c) return mat;
        vector<vector<int>> vec(r, vector<int>(c));
        int i = 0, j = 0;
        auto next = [&]() {
            if (j == m) j = 0, i++;
            return mat[i][j++];
        };
        for (int i = 0; i < r; i++) 
            for (int j = 0; j < c; j++) 
                vec[i][j] = next();
        return vec;
    }
};