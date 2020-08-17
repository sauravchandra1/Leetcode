class Solution {
public:
    vector<int> findDiagonalOrder(vector<vector<int>>& matrix) {
                
        vector<int> vect;
        
        int i = 0;
        int j = 0;
        
        int m = matrix.size() -1;
        if (m == -1)
            return vect;
        
        int n = matrix[0].size() -1;
        
        
            while (i <= m && j <= n) {
                
                if ((i+j)%2 == 0 && i <= m && j <= n) {
                    
                    if (i > 0 && j < n) {
                        vect.push_back(matrix[i][j]);
                        i--;
                        j++;    
                    }
                    else if (i == 0 && j != n) {
                        vect.push_back(matrix[i][j]);
                        j++;
                    }
                    else if (j == n) {
                        vect.push_back(matrix[i][j]);
                        i++;
                    };                        
                }
                
                if ((i+j)%2 == 1 && i <= m && j <= n) {
                    if (j > 0 && i < m) {
                        vect.push_back(matrix[i][j]);
                        i++;
                        j--; 
                    }
                    else if (j == 0 && i != m) {
                        vect.push_back(matrix[i][j]);
                        i++;
                    }
                    else if (i == m) {
                        vect.push_back(matrix[i][j]);
                        j++;
                    };                    
                       
                }
            };
        
        return vect;            
    }
};