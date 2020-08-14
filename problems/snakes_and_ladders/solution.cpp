class Solution {
    public:
        struct node {
            int val;
            int dist;
        };
    node temp, a;
    int bfs(vector < int > & move, bool * vis, int N) {
        queue < node > s;
        s.push({
            1,
            0
        }), vis[1] = true;
        while (!s.empty()) {
            temp = s.front();
            if (temp.val == N)
                break;
            s.pop();
            for (int i = temp.val + 1; i <= temp.val + 6 && i <= N; i++)
                if (!vis[i]) {
                    a.dist = temp.dist + 1;
                    vis[i] = true;
                    a.val = (move[i] == -1) ? i : move[i];
                    s.push(a);
                }
        }
        if (s.empty())
            return -1;
        else
            return temp.dist;
    }

    int snakesAndLadders(vector < vector < int >> & board) {
        int n = board.size();
        int total = n * n;
        bool vis[total + 1];
        memset(vis, 0, sizeof(vis));
        vis[0] = true; 
        vector < int > move(total + 1);
        move[0] = -1;
        bool flag = false;
        int j = 1;
        for (int i = n - 1; i >= 0; i--) { 
            vector < int > temp = board[i];
            if (flag == true)
                reverse(temp.begin(), temp.end()), flag = false;
            else
                flag = true;
            for (int k = 0; k < n; k++)
                move[j++] = temp[k];
        }
        return bfs(move, vis, total);
    }
};