class Solution {
public:
 int numBusesToDestination(vector<vector<int>>& routes, int S, int T){
        if(S == T) return 0; // must
        unordered_map<int, vector<int> > buses4stop; 
        for(int i = 0; i < routes.size(); i++)
            for(const auto& stop: routes[i])
                buses4stop[stop].emplace_back(i);
        queue<int> q{{S}};        
        vector<bool>visited(routes.size());        
                 
        for(int step = 0;!q.empty(); step++)
            for(int sz = q.size(); sz-- > 0; ){
                const int cur = q.front(); q.pop();                                
                for(const auto& bus: buses4stop[cur]){
                    if(visited[bus]) continue;
                    visited[bus] = 1;
                    for(const auto& next: routes[bus]){                       
                        if(next == T) return step + 1;                
                        q.emplace(next);               
                    }
                }
            }            
        
        return -1;
    }
}; 