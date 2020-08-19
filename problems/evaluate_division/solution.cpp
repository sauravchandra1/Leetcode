class Solution {
    public:
        vector < double > calcEquation(vector < vector < string >> & eqn, vector < double > & values, vector < vector < string >> & queries) {
            map < string, vector < pair < string, double >>> graph;
            for (int i = 0; i < eqn.size(); i++) {
                graph[eqn[i][0]].push_back({
                    eqn[i][1],
                    values[i]
                });
                graph[eqn[i][1]].push_back({
                    eqn[i][0],
                    1 / values[i]
                });
            }
            vector < double > res;
            for (int i = 0; i < queries.size(); i++) {
                string s = queries[i][0];
                string d = queries[i][1];
                unordered_set < string > v;
                double ans = -1;
                if (graph.find(s) != graph.end())
                    dfs(s, d, graph, v, ans, 1.0);
                res.push_back(ans);
            }
            return res;
        }
    void dfs(string s, string d, map < string, vector < pair < string, double >>> graph, unordered_set < string > visited, double & ans, double tmp) {
        if (visited.find(s) != visited.end())
            return;
        else {
            visited.insert(s);
            if (s == d) {
                ans = tmp;
                return;
            } else {
                for (auto it: graph[s]) {
                    dfs(it.first, d, graph, visited, ans, tmp * it.second);
                }
            }
        }

    }
};