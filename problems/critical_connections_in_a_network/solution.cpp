
// // https://www.bilibili.com/video/BV19J411J7AZ?p=5

// Basically, it uses dfs to travel through the graph to find if current vertex u, 
// can travel back to u or previous vertex
// low[u] records the lowest vertex u can reach
// dfn[u] records the time when u was discovered

class Solution {
public:
    Solution() {ios::sync_with_stdio(false); std::cin.tie(nullptr); std::cout.tie(nullptr);}
    
    vector<vector<int>> criticalConnections(int n, vector<vector<int>>& connections) {
        vector<vector<int>> g(n);
        for(auto &edge : connections){
            g[edge[0]].push_back(edge[1]); // build graph
            g[edge[1]].push_back(edge[0]);
        }

        int time = 0;
        vector<int> low(n, -1);
        vector<int> dfn(n, -1);
        vector<vector<int>> res;
        for(int i = 0; i < n; ++i) if(dfn[i] == -1){
            dfs(i, i, time, g, low, dfn, res);
        }
        return res;
    }
    
    void dfs(int u, int pNode, int &time, vector<vector<int>> &g, 
             vector<int> &low, vector<int> &dfn, vector<vector<int>> &res)
    {
        
        low[u] = dfn[u] = time++; // discover u
        
        for(int v : g[u]){
            if(v == pNode) continue; // if parent vertex, ignore
            // if not discovered
            if(dfn[v] == -1){
                dfs(v, u, time, g, low, dfn, res);
                
                low[u] = min(low[u], low[v]);
                if(dfn[u] < low[v]){
                    res.push_back({u, v}); // u - v is critical, there is no path for v to reach back to u or previous vertices of u
                }
            } else{
                low[u] = min(low[u], dfn[v]); // if v discovered and is not parent of u, update low[u], cannot use low[v] because u is not subtree of v
            }
        }
    }
};