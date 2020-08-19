class Solution {
    public:
        bool isBipartite(vector < vector < int >> & graph) {
            int n = graph.size();
            bool possible = true;
            vector < int > col(n, -1);
            vector < bool > visited(n, false);

            for (int i = 0; i < n; i++) {
                if (!visited[i]) {
                    col[i] = 0;
                    stack < int > s;
                    s.push(i);
                    visited[i] = true;
                    while (!s.empty()) {
                        int u = s.top();
                        s.pop();
                        for (int v: graph[u]) {
                            if (col[v] == col[u]) {
                                possible = false;
                                break;
                            }
                            if (!visited[v]) {
                                col[v] = 1 ^ col[u];
                                s.push(v);
                                visited[v] = true;
                            }
                        }
                    }
                }
            }
            return possible;
        }
};