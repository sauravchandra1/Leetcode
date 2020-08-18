class Solution {
public:
    struct cmp {
        bool operator()(const tuple<int, int, int> &a, tuple<int, int, int> &b) {
            return (get<0>(a) > get<0>(b));
        }
    };
    priority_queue<tuple<int, int, int>, vector<tuple<int, int, int>>, cmp> Q;
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int K) {
        vector<vector<int>> tree(n);
        map<pair<int, int>, int> mp;
        for (auto v : flights) {
            tree[v[0]].push_back(v[1]);
            mp[make_pair(v[0], v[1])] = v[2];
        }
        K++;
        vector<int> dist(n + 1, 0);
        vector<bool> seen(n + 1, false);
        int d = 0;
        int ans = INT_MAX;
        Q.push(make_tuple(0, src, 0));
        while (!Q.empty()) {
            int cost, source, d;
            tie(cost, source, d) = Q.top();
            Q.pop();
            if (d > K) continue;
            if (source == 10) {
            }
            seen[source] = true;
            dist[source] = d;
            if (source == dst) {
                return cost;
            }
            for (auto node : tree[source]) {
                if (!seen[node]) {
                    Q.push(make_tuple(cost + mp[make_pair(source, node)], node, d + 1));
                }
                if (seen[node] && d + 1 < dist[node]) {
                    Q.push(make_tuple(cost + mp[make_pair(source, node)], node, d + 1));
                }
            }   
        }
        if (ans == INT_MAX) return -1;
        return ans;
    }
};