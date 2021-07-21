class Solution {
public:
    string pushDominoes(string dom) {
        int len = dom.size();
        queue<int> Q;
        vector<int> visited(len, len);
        for (int i = 0; i < dom.size(); i++) {
            if (dom[i] != '.') {
                Q.push(i);
                visited[i] = 0;
            }
        }
        int t = 0;
        int l, idx;
        while (!Q.empty()) {
            l = Q.size();
            t++;
            for (int i = 0; i < l; i++) {
                idx = Q.front();
                Q.pop();
                if (dom[idx] == 'R') {
                    if (idx == len - 1) continue;
                    if (idx + 1 < len && dom[idx + 1] == '.') {
                        if (idx + 2 < len && dom[idx + 2] == 'L' && visited[idx + 2] < t) continue;
                        dom[idx + 1] = 'R';
                        Q.push(idx + 1);
                        visited[idx + 1] = t;
                    }
                } else {
                    if (idx == 0) continue;
                    if (idx - 1 >= 0 && dom[idx - 1] == '.') {
                        if (idx - 2 >= 0 && dom[idx - 2] == 'R' && visited[idx - 2] < t) continue;
                        dom[idx - 1] = 'L';
                        Q.push(idx - 1);
                        visited[idx - 1] = t;
                    }
                }
            }
        }
        return dom;
    }
};