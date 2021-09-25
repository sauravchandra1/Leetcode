using tpii = tuple<pair<int, int>, int, int>;
using pii = pair<int,int>;
#define gett(t, i) (std::get<i>(t))

struct tpiicomp {
    bool operator()(const tpii& a, const tpii& b) const{
        return gett(a, 1) == gett(b, 1) ? gett(a, 2) > gett(b, 2) : gett(a, 1) > gett(b, 1);
    }
};
struct piihash {
    size_t operator()(const pii& a) const{
        return (hash<int>()(a.first) ^ hash<int>()(a.second));
    }
};
struct piicomp {
    bool operator()(const pii& a, const pii& b) const{
        return a.first == b.first && a.second == b.second;
    }
};

class Solution {
public:
    int shortestPath(vector<vector<int>>& grid, int k) {
        int n = grid.size();
        int m = grid[0].size();
        vector<vector<int>> dirs{{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
        
        priority_queue<tpii, vector<tpii>, tpiicomp> pq;
        pq.emplace(make_pair(0,0), 0, 0);
        unordered_map<pii, int, piihash, piicomp> seen;
        seen[make_pair(0, 0)] = 0;
        
        while(!pq.empty()) {
            tpii curr = pq.top();
            pq.pop();
            
            pii pos = gett(curr, 0);
            if(gett(curr, 2) > k) continue;
            if(pos.first == n - 1 && pos.second == m - 1) return gett(curr, 1);
            
            for(vector<int>& d : dirs) {
                int newi = pos.first + d[0];
                int newj = pos.second + d[1];
                
                if(newi < 0 || newi >= n || newj < 0 || newj >= m) continue;
                pii newPos = make_pair(newi, newj);
                int obs = gett(curr, 2) + (grid[newi][newj] == 1);
                if(seen.count(newPos) && seen[newPos] <= obs) continue;
                seen[newPos] = obs;
                
                pq.emplace(newPos, gett(curr, 1) + 1, obs);
            }
        }
        
        return -1;
    }
};