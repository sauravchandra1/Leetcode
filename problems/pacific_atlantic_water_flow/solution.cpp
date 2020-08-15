class Solution {
public:
    vector<vector<int>> pacificAtlantic(vector<vector<int>>& matrix) {
        vector<vector<int>> ret;
        int m = matrix.size();
        
        if(m <= 0)
            return(ret);
        
        int n = matrix[0].size();
        
        vector<vector<int>> atl (m, vector<int> (n, 0));
        vector<vector<int>> pac (m, vector<int> (n, 0));
        
        vector<vector<int>> st_atl, st_pac;
        
        
        for(int j = 0; j < n; ++j) {
            st_atl.push_back({m - 1, j});
        }
        
        for(int i = 0; i + 1 < m; ++i) {
            st_atl.push_back({i, n - 1});
        }
        
        for(int i = 0; i  < m; ++i) {
            st_pac.push_back({i, 0});
        }
        
        for(int j = 1; j < n; ++j) {
            st_pac.push_back({0, j});
        }
        
        
        bfs(matrix, atl, st_atl);
        bfs(matrix, pac, st_pac);
        
        
        
        
        for(int i = 0; i < m ; ++i) {
            for(int j = 0; j < n; ++j) {
                if(atl[i][j] && pac[i][j]) {
                    vector<int> cur = {i, j};
                    ret.push_back(cur);
                }
            }
        }
        
        return(ret);
    }
    
    void bfs(vector<vector<int>>& matrix, vector<vector<int>> &vis, vector<vector<int>> &st) {
        vector<int> dx = {1, 0, -1, 0};
        vector<int> dy = {0, 1, 0, -1};
        queue<vector<int>> q;
        int m = matrix.size();
        int n = matrix[0].size();
        
        for(auto & e : st) {
            q.push(e);
            vis[e[0]][e[1]] = 1;
        }
        
        while(!q.empty()) {
            int sz = q.size();
            
            while(sz > 0) {
                sz--;
                
                auto cur = q.front();
                q.pop();
                
                for(int k = 0; k < 4; ++k) {
                    int x = cur[0] + dx[k];
                    int y = cur[1] + dy[k];
                    
                    if(x < 0 || y < 0 || x >= m || y >= n)
                        continue;
                    
                    if(vis[x][y] || vis[x][y])
                        continue;
                    
                    if(matrix[cur[0]][cur[1]] <= matrix[x][y]) {
                        vis[x][y] = 1;
                        q.push({x, y});
                    }
                }
                
            }
        }
    }
};